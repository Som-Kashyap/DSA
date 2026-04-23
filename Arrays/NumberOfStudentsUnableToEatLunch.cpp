#include<iostream>
#include<vector>

using namespace std;

int UnableToEat ( vector<int>students , vector<int>sandwiches ) {

    int didnoteat = sandwiches.size();

    vector<int>count ( 2 , 0 );

    for ( int val : students ) count[val]++;

    for ( int x : sandwiches ) {

        if ( count[x] == 0 ) break;

        if ( didnoteat == 0 ) break;

        count[x]--;

        didnoteat--;

    }

    return didnoteat;

}

int main () {

    vector<int>students = {1,1,0,0};
    vector<int>sandwiches = {0,1,0,1};

    cout<<"Number of students unable to eat lunch : "<<UnableToEat( students , sandwiches )<<endl;

    return 0;

}