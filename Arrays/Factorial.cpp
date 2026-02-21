#include<iostream>

using namespace std;

int factorial(int nums){

    int fac;

    if(nums==0 || nums==1){
        fac=1;
    }else{
        fac = nums*factorial(nums-1);
    }

    return fac;
}
int main(){

    int nums;

    cout<<"Enter any integer: "<<endl;
    cin>>nums;

    cout<<"factorial = "<<factorial(nums)<<endl;

    return 0;

}