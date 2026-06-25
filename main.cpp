#include "include/DynamicArray.h"
#include <bits/stdc++.h>
using namespace std;

class student {

};

int main(){
    DynamicArray<int>d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    for(int i=0;i<d.size();i++){
        cout<<d[i]<<endl;
    }

}