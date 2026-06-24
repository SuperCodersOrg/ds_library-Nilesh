#include<iostream>
#include "DynamicArray.h"
using namespace std;

int main(){
    DynamicArray<int>a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cout<<"Capacity: "<<a.capacity()<<endl;
    a.insert(0,5);
    cout<<"Capacity: "<<a.capacity()<<endl;
    a.insert(3,10);
    cout<<"Capacity: "<<a.capacity()<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
}