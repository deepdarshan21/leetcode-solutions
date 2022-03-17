#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status:
   Runtime: 5 ms faster than: 39.93%
   Memory Usage: 8.6 MB less than: 38.30%
   Remarks:
*/

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> res;
        for (auto num : nums) {
            sum += num;
            res.push_back(sum);
        }
        return res;
    }
};