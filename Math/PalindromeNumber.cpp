// Problem : Check if a number is palindrome

// Approach : Reversed num is created after checking for non-possible cases ( num should neither be 0 nor a multiple of 10 or negative)

// Result : num is palindrome if reversed num == num

#include<iostream>

using namespace std;

bool IsPalindrome ( int x ) {

    long long num = x;
    long long rev = 0;

    if ( x <= 0  || ( x%10 == 0 && x!=0 ) ) return false;

    while ( num != 0 ) {

        rev = rev*10 + num%10;

        num /= 10;

    }

    return ( x == rev );
}

int main () {

    int x = 121;

    cout<<IsPalindrome(x)<<endl;

    return 0;
}