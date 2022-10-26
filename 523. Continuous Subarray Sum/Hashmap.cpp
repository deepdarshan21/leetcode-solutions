#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashmap
        To understand this question, you have to understand how remainders work. If k = 5,
        then 6 % 5 = 1, which also means (6 + 5) % 5 = 1. So you use a hash map to check if
        you have seen that remainder before. If yes, then you know between both indexes,
        it is 5 (i.e. (6 + 5) - 6 = 5). This question tests nothing other than knowing how
        remainders work.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 217 ms faster than: 98.46%
   Memory Usage: 113.8 MB less than: 46.74%
   Remarks:
*/

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum % k) == mp.end())
                mp[sum % k] = i + 1;
            else if (mp[sum % k] < i)
                return true;
        }
        return false;
    }
};