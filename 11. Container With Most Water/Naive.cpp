#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Brute Force
        Check for every possible conditions

   Edge Cases:


   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
*/

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int maxContainer = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int minHeight = min(height[i], height[j]);
                maxContainer = max(maxContainer, (j - i) * minHeight);
            }
        }
        return maxContainer;
    }
};