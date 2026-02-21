#include<iostream>
#include<string>

using namespace std;

int main(){

    string str;
    cout<<"Enter string : "<<endl;
    getline(cin,str);

    cout<<"Length of the string : "<<str.length()<<endl;
    cout<<"String : "<<str<<endl;
    
    return 0;
}