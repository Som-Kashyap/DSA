#include<iostream>

using namespace std;

int Tn(int num){

    //Tn = sum of all thr natural numbers till n

    int An = (num*(num+1)/2);

    return An;
}
int main(){

    int num;
    cout<<"Enter an term number : "<<endl;
    cin>>num;

    cout<<"The term is : "<<Tn(num)<<endl;

    return 0;
}