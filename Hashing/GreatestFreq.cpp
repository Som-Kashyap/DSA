 #include<iostream>
 #include<vector>
 #include<unordered_map>
 #include<climits>
 
 using namespace std;

 int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int , int>m;
        int max = INT_MIN;
        int ans=0;

        for ( int val : nums ){
            m[val]++;
        }

        for ( int i = 0; i<nums.size() ; i++ ){
            if(m[i]>max){
                max=m[i];
                ans = max;
            }
        }
        return ans;
    }