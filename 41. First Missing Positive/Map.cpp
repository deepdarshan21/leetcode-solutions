#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Use map to store every element of vector, and check which smallest element not exist in map

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 99 ms faster than: 61%
   Memory Usage: 46.6 MB less than: 21.93%
   Remarks:
*/

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int res = 1;
        while (mp[res] != 0) res++;
        return res;
    }
};