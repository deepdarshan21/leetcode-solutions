#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 40 ms faster than: 69.04%
   Memory Usage: 27 MB less than: 16.52%
   Remarks:
*/

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for (auto num : nums) {
            res.push_back(num * num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};