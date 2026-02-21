#include <iostream>
#include <vector>

using namespace std;

int Diff(vector<int> &nums)
{

    vector<int> digits;
    int DigSum=0 ;
    int ArrSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        ArrSum += nums[i];

        

        while( nums[i]>0 ){


        int num = abs(nums[i]);

        int digit = num % 10;
        digits.push_back(abs(digit));
        num /= 10;

        
    } 
    if(nums[i]==0){
        int num = (nums[i]);
            digits.push_back(num);
        }

     
       
    }

    // for (int val : digits)
    // {
    //     // DigSum += val;
    //     return val;
    // }

    for(int i=0 ;i <digits.size(); i++){
        cout<<digits[i]<<" ";
    }
    cout<<endl;
 
    // return DigSum;
    //  return ArrSum;
    //  return abs(ArrSum - DigSum);

    return 0;
}
int main()
{

    vector<int> nums = {-12 , 0 ,10};

    cout << Diff(nums) << endl;

    return 0;
}