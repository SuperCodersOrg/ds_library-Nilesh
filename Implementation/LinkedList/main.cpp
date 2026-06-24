#include "LinkedList.h"
#include<vector>
using namespace std;



class test{
    string name;

};
int main(){
    

    LinkedList<int>l;
    l.append(1);
    l.length();
    l.print();
    l.append(2);
    l.length();
    l.print();
    l.append(3);
    l.length();
    l.print();
    l.append(4);
    l.length();
    l.print();
    l.append(5);
    l.length();
    l.print();
    l.append(6);
    l.length();
    l.print();
    l.append(7);
    l.length();
    l.print();
    l.append(8);
    l.length();
    l.print();
    l.append(9);
    l.length();
    l.print();
    LinkedList<int>l2(l);
    

    
    cout<<"Second LInkedList\n";
    l2.print();
    l2.clear();
    l2.pop();
    l2.print();
    l2.pop();
    l2.print();
    l2.pop();
    l2.print();
    l2.pop();
    l2.print();
    l2.pop();
    l2.print();
    l2.pop();
    l2.print();
    


    
}