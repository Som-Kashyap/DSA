#include<iostream>
#include<string>

using namespace std;

bool DetectCapital(string s){

    for(int i = 0; i<s.length(); i++){

            if( 'a'<=s[i] && s[i]<='z'){

                return false;
            }

    }

    return true;
}

int main () {

    string s = "lEEtCoDe";

    DetectCapital(s);

    return 0;
}