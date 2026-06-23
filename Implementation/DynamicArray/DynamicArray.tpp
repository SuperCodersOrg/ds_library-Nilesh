#include "DynamicArray.h"
#include <type_traits>
#include <stdlib.h>
#include <new>
#include <stdexcept>


// Private helping methods

// Deallocate non primitive data type
template<typename T> void
DynamicArray<T>::destroyAndFree(T *ptr,int count) {
    if constexpr (!std::is_trivially_destructible_v<T>) { 
        for (int i = 0; i < count; i++) {
            ptr[i].~T();
        }
    }
    free(ptr);          
}

// Destructor
template<typename T> DynamicArray<T>::~DynamicArray(){
    destroyAndFree(arr,len);
    
}

// Delete element by Index
template<typename T> void DynamicArray<T>::del(int index){

    if(index<0 || index >=len){
        throw std::out_of_range("Index oit of range");
    }
    if constexpr(!std::is_trivially_destructible_v<T>){
        arr[index].~T();
    }
    
}


// --------------------------------------------------------------------


// public methods

// Default Constructor
template<typename T >DynamicArray<T> :: DynamicArray(){
    len=0;
    cap=4;
    arr= (T*)malloc(cap * sizeof(T));
    if(arr==nullptr){
        throw std::bad_alloc();
    }
}


// Parametrised Constructor
template<typename T >DynamicArray<T> :: DynamicArray(int cap,T val){
    if(cap<=0){
        throw std::invalid_argument("Capacity is invalid!");
    }
    arr = (T*)malloc(cap * sizeof(T));
    if(arr==nullptr){
        throw std:: bad_alloc();
    }
    
    
    this->cap=cap;
    len=0;
    try{
        for(;len<cap;len++){
            new (&arr[len]) T(val);
        }
    }
    catch(...){
        destroyAndFree(arr,len);
        throw;
    }
}

// Copy Constrctor
template<typename T> DynamicArray<T>::DynamicArray(const DynamicArray &others){
    cap=others.cap;
    len=others.len;

    for(int i=0;i<len;i++){
        //arr.push_back(others.arr[i]);
        // Continue Tomorrow
    }

}

// Resizing the Array
template<typename T> void DynamicArray<T>:: resize(){
    int newsize=cap*2;
    T *newarr=(T*)malloc(newsize*sizeof(T));

    // malloc memory nhi de paye to nullptr deta hai
    if(newarr==nullptr){
        throw std :: bad_alloc();
    }

    int i=0;

    try{
        for(;i<len;i++){
            new(&newarr[i]) T(arr[i]);
        }

    }
    catch(...){
        destroyAndFree(newarr,i);
        throw;
    }
    destroyAndFree(arr,len);
    arr=newarr;
    cap=newsize;
}

// push_back
template<typename T> void DynamicArray<T>:: push_back(const T& val){
    if(len==cap){
        resize();
    }
    new(&arr[len])T(val);
    len++;
}

// pop
template<typename T>void DynamicArray<T>::pop_back(){
    if(len==0){
        throw std::underflow_error("Array is empty");
    }
    del(len-1);
    len--;
    
}



// Operator[] overloading 
template<typename T> T& DynamicArray<T>::operator[](int index){
    if(index<0 || index>=len){
        throw std:: out_of_range("Index out of range");
    }
    return arr[index];
}

// Operator[] const overloading
template<typename T> const T& DynamicArray<T>::operator[](int index) const{
    if(index<0 || index>=len){
        throw std:: out_of_range("Index out of range");
    }
    return arr[index];
}


// insert
template<typename T> void DynamicArray<T>:: insert(int index,T val){
    if(index<0 || index> len){
        throw std::out_of_range("Index out of range");
    }
    if(index==len){
        push_back(val);
        return ;
    }
    
    if(len==cap){
        resize();
    }

    for(int i=len;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=val;
    len++;
}

// remove
template<typename T> void DynamicArray<T> :: remove(int index){
    if(index<0 || index>=len){
        throw std::out_of_range("Index out of range");
    }

}

// size
template<typename T> int DynamicArray<T>:: size()const{
    return len;
}
// capacity
template<typename T> int DynamicArray<T>:: capacity()const{
    return cap;
}