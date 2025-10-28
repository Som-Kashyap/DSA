#include<iostream>
#include<vector>

using namespace std;

int Diff( int n){

    

    int Sum = (n*(n+1)/2);

    int SqSum = Sum*Sum;
    

    int SumOfSq = (n*(n+1)*(2*n+1))/6;

    int diff = (SumOfSq-SqSum);

    return diff;
}
int main(){

    int n = 30;

    Diff(n);

    return 0;
}