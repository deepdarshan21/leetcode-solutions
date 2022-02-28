#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 49 ms faster than: 56.75%
   Memory Usage: 21.9 MB less than: 24.23%
   Remarks:
*/

class Solution {
   public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a, b, c, n = nums.size();
        a = n - 1;
        b = n - 2;
        c = n - 3;
        while (c >= 0) {
            if ((nums[c] + nums[b]) > nums[a]) {
                break;
            }
            a = b;
            b = c;
            c = c - 1;
        }
        if (c < 0) {
            return 0;
        }
        return (nums[a] + nums[b] + nums[c]);
    }
};