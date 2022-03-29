#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashing
        Use unordered_map for counting freq of elements.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 372 ms faster than: 7.48%
   Memory Usage: 84 MB less than: 15.65%
   Remarks:
*/

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
            if (mp[num] > 1) {
                return num;
            }
        }
        return 0;
    }
};