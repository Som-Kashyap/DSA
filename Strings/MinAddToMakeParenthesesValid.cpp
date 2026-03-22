#include<iostream>

using namespace std;

int MinAdd ( string s ){

    int open = 0 , close = 0;

    for ( int i = 0; i < s.length(); i++ ) {

        if ( s[i]=='(' ) {
            open++;
        }
        else{

            if ( open>0 ) {
                open--;
            }
            else{
                close++;
            }
        }
    }
    int ans = open+close;

    return ans;

}

int main () {

    string s = "((()(";

    cout<<"Minimum additions: "<<MinAdd(s)<<endl;

    return 0;
}