#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashing
        Store the frequency of each element in hash set

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 46 ms faster than: 8.68%
   Memory Usage: 19.6 MB less than: 52.27%
   Remarks:
*/

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }
        int ans;
        for (auto i : counts) {
            if (i.second > nums.size() / 2) {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};