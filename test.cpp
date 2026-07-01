#include <iostream>
#include <sstream>
using namespace std;

int main() {

    string str;
    getline(cin,str);
    stringstream ss(str);

    string method;
    string key;
    string val="";
    string strm="";

    ss>>method;
    ss>>key;

    while(!ss.fail()){
        cout<<ss.fail()<<endl;
        ss>>strm;
        val=val+strm;
    }
    

    cout<<"Method: "<<method<<endl;
    cout<<"Key: "<<key<<endl;
    cout<<"Val: "<<val<<endl;

    cout<<ss.fail();
    

    

}