#include <bits/stdc++.h>
using namespace std;

/*
    Approach: 
       

   Edge Cases:
       

   Time Complexity: O(n) Space: O(n)
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> store;
        for (int i = 0; i < nums.size(); i++) {
            if (store.find(target - nums[i]) != store.end()) {
                ans.push_back(store[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            store[nums[i]] = i;
        }
        return ans;
    }
};