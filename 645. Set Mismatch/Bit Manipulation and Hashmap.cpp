#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation and Hashmap

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 63 ms faster than: 56.81%
   Memory Usage: 30.9 MB less than: 17.45%
   Remarks:
*/

class Solution {
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> ump;
        int x, y, z = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            z = z ^ (i + 1) ^ nums[i];
            ump[nums[i]]++;
            if (ump[nums[i]] == 2) x = nums[i];
        }
        y = z ^ x;
        return {x, y};
    }
};