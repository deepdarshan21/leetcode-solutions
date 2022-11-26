#include <bits/stdc++.h>
using namespace std;

/*
   Approach:

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 343 ms faster than: 30.22%
   Memory Usage: 57.9 MB less than: 36.07%
   Remarks:
*/

class Solution {
   public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), res = 0, i = 0;
        while (i < n) {
            int start = i, count = 0, first = -1, last = -1;
            while (i < n && nums[i] != 0) {
                if (nums[i] < 0) {
                    count++;
                    if (first == -1) first = i;
                    last = i;
                }
                i++;
            }

            // cout<<count<<" "<<first<<" "<<last<<endl;
            if (count % 2 == 0)
                res = max(res, i - start);
            else
                res = max({res, i - first - 1, last - start});
            while (i < n && nums[i] == 0) {
                i++;
            }
        }
        return res;
    }
};