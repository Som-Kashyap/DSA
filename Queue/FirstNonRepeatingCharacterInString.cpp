
// Problem : First Unique character in a string

// Approach : using hashmap to store frequencies of characters present in the string while pushing elements to the queue , then removing duplicates from the queue using while loop

// Logic : After while loop ends , q.front() returns first unique character

#include<iostream>
#include<queue>
#include<unordered_map>
#include<cctype>

using namespace std;

char FirstNonRepeating ( string s ) {

    queue<char>q;
    unordered_map<char , int>freq;

    for ( char c : s ) {

        if (isalnum(c) ) {

        freq[c]++;
        q.push ( c );

        }

    }

    while ( !q.empty() && freq[q.front() > 1 ] ) {

        q.pop();

    }

    return q.front();

}

int main () {

    string s = "$datastructures";

    cout<<"First unique: "<<FirstNonRepeating(s)<<endl;

    return 0;
}