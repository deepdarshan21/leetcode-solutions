#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using extra space
        At any place water traped can be min of (max of its left and max of its right) minus height at that point

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 29 ms faster than: 41.88%
   Memory Usage: 20.7 MB less than: 11.3%
   Remarks:
*/

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i - 1], height[i + 1]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int tmp = min(maxLeft[i], maxRight[i]) - height[i];
            if (tmp > 0) res += tmp;
        }
        return res;
    }
};