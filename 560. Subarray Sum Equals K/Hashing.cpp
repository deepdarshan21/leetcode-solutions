#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exeeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        int tempSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            tempSum += nums[i];
            mp[i] = tempSum;
        }
        tempSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int size = 1; size <= nums.size() - i; size++) {
                if ((mp[i + size - 1] - tempSum) == k) {
                    count++;
                }
            }
            tempSum = +nums[i];
        }
        return count;
    }
};