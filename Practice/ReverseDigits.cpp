#include<iostream>
#include<vector>

using namespace std;

int Reverse(int num) {
    vector<int> digits;

    // Extract digits
    while (num > 0) {
        int digit = num % 10;
        digits.push_back(digit);
        num /= 10;
    }

    // Construct the reversed number
    int reversedNum = 0;
    for (int val : digits) {
        reversedNum = reversedNum * 10 + val;
    }
    
    return reversedNum; // Return the complete reversed number
}

int main() {
    int num = 234;
    int reversed = Reverse(num);
    cout << "Reversed Number: " << reversed << endl; // Output the reversed number
    return 0;
}

