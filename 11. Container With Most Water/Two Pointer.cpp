#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Two Pointer
        First we take maximum width as we take '(end-start)=sizeof(height)', then we check for
        maximizing the area by increasing height and decreasing weidth as less as possible

   Edge Cases:


   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 109 ms faster than: 57.55%
   Memory Usage: 59.1 MB less than: 35.66%
*/

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int maxContainerArea = 0, minHeight;
        int start = 0, end = height.size() - 1;
        while (start < end) {
            minHeight = min(height[start], height[end]);
            maxContainerArea = max(maxContainerArea, (end - start) * minHeight);
            if (minHeight == height[start]) {
                start++;
            } else {
                end--;
            }
        }
        return maxContainerArea;
    }
};