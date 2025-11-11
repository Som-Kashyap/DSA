#include <iostream>
#include <vector>

using namespace std;

bool IsDivisible(int num)
{

    int NUM;
    vector<int> digits;

    int digit = num % 10;
    digits.push_back(digit);
    num /= 10;

    digits.pop_back();

    for(int val : digits){
         NUM = NUM*10+1;
    }
    if(NUM%4==0){
        return true;
    }else{
        return false;
    }
   

    
    
}
int main()
{

    int num;
    cout << "Enter an integer: " << endl;
    cin >> num;

    return 0;
}