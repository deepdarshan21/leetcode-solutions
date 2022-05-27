#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Upper Bound with extra space
      Use extra space to store the 2's power

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 195 ms faster than: 36.87%
   Memory Usage: 49.8 MB less than: 57.69%
   Remarks:
*/

class Solution {
   public:
    int numSubseq(vector<int>& nums, int target) {
        int count = 0;
        const int mod = 1e9 + 7;
        vector<int> store(nums.size() + 1);
        int temp = 1;
        store[0] = temp;
        for (int i = 1; i < store.size(); i++) {
            temp = (temp * 2) % mod;
            store[i] = temp;
        }
        sort(nums.begin(), nums.end());
        for (int min = 0; min < nums.size(); min++) {
            int max = upper_bound(nums.begin() + min, nums.end(), target - nums[min]) - nums.begin() - 1;
            // cout<<min<<" "<<max<<endl;
            if (max < min) {
                continue;
            }
            int temp = max - min;
            if (temp < 0) {
                temp = 0;
            }
            // cout<<"Adding... "<<store[temp]<<endl;
            count = (count + store[temp]) % mod;
        }
        return count;
    }
};