// Problem LC: 1054

// Approach: Hash-map is used to store freq of each element, maxfreq and corresponding maxval are retrieved, the most freq element is
//           placed at even idxs, after that, remaining elements are placed at odd idxs.
//        (placing the most freq element first ensures that adjacency is removed, as rest of the elements will be placed in remainaing gaps)

// TC: O(N)
// SC: O(n), n is the number of unique elements


#include<bits/stdc++.h>

using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        unordered_map<int,int> freq;

        int maxCount, maxVal;

        for ( int& val : barcodes ) {
            freq[val]++;
        }

        for ( auto& it : freq ) {

            if ( it.second > maxCount ) {
                maxCount = it.second;
                maxVal = it.first;
            }
        }

        int i = 0;
        int n = barcodes.size();
        vector<int> res(n);
        
        while ( freq[maxVal] > 0 ) {

            res[i] = maxVal;

            freq[maxVal]--;

            i += 2;

        }

        for ( auto& it : freq ) {

            while ( it.second > 0 ) {

                if ( i >= n ) i = 1;
               
            res[i] = it.first;
            i += 2;
            it.second--;

            }
           
        }
        return res;
    }