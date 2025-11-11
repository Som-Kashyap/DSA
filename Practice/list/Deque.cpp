#include<iostream>
#include<deque>

using namespace std;

int main() {

    deque<int>d;
    int sum;

    d.push_back(1);
    d.push_back(2);
     d.push_back(3);
    d.push_back(4);
     d.push_back(5);
    d.push_back(6);

   for(int i=0; i<d.size() ; i++){
    sum+=d[i];
   }

   return sum;

}