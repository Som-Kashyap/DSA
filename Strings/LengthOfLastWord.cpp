#include<iostream>
#include<string>

using namespace std;

int Length(string s){

    int length=0;
    int end = s.length()-1;
     int st = end;

    while ( end == ' '){
        end--;
    }
    while ( end !=' '){
       st--;
    }

    return abs(end-st);
   
}
int main() {

    string s;
    cout<<"Enter String: "<<endl;
    getline(cin ,s);

    cout<<Length(s)<<endl;

    return 0;
}