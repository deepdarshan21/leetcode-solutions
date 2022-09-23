#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 2202 ms faster than: 26.05%
   Memory Usage: 232.3 MB less than: 44.31%
   Remarks:
*/

class Solution {
   public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> store;
        for (int i = 0; i < n; i++) {
            int temp = k;
            vector<int> tempStore;
            for (int j = i; j < n; j++) {
                if (nums[j] % p == 0) temp--;
                tempStore.push_back(nums[j]);
                // cout<<tempStore<<endl;
                if (temp == -1) break;
                store.insert(tempStore);
            }
        }
        // for(int itr: store) cout<<itr<<endl;
        return store.size();
    }
};