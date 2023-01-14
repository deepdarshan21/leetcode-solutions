#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 23 ms faster than: 55.1%
   Memory Usage: 19.8 MB less than: 64.5%
   Remarks:
*/

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int low = 0, high = n - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        while (low <= high) {
            if (leftMax <= rightMax) {
                int tmp = leftMax - height[low];
                if (tmp > 0) res += tmp;
                leftMax = max(leftMax, height[low]);
                low++;
            } else {
                int tmp = rightMax - height[high];
                if (tmp > 0) res += tmp;
                rightMax = max(rightMax, height[high]);
                high--;
            }
        }
        return res;
    }
};