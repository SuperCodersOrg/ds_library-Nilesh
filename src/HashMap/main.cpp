#include "HashMap.h"
#include <iostream>
using namespace std;

class student{

}
;
int main(){
    student s;
    HashMap<student ,int>mp;
    mp.insert(s,1);
    cout<<mp.get(s);

}