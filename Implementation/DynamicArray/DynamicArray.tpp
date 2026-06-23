#include "DynamicArray.h"
#include <type_traits>
#include <stdlib.h>
#include <new>


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
    if constexpr(!std::is_trivially_destructible_v<T>){
        arr[index].~T();
    }
    else{
        
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
template<typename T> void DynamicArray<T>:: push_back(T val){
    if(len==cap){
        resize();
    }
    new(&arr[len])T(val);
    len++;
}

// pop
template<typename T>void DynamicArray<T>::pop_back(){

    
}

