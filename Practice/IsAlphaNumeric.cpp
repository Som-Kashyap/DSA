#include<iostream>

using namespace std;

bool IsAlphaNum(char c){

    if(('0'<=c && c<='9' )|| ('a'<=c && c<='z')){
        return true;
    }
    else{
        return false;
    }
}
int main(){

    char c;
    cout<<"Enter character: "<<endl;
    cin>>c;

    if(IsAlphaNum(c)){
        cout<<"It is alpha numeric!"<<endl;
    }else{
        cout<<"It is not alpha numeric! "<<endl;
    }

    return 0;
}