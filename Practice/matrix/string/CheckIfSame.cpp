#include<iostream>
#include<string>

using namespace std;

bool IsSame(string s1 , string s2){

    cout<<(s1==s2)<<endl;
}
int main(){

   string s1="HemloGuyms";
   string s2="Hemloguyms";

   IsSame(s1,s2);

   return 0;

}