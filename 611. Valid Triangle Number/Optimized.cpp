#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Linear Search
        First sort the nums, then take first and second element with while loop and find the position
        of the third element with linear searching and move your searching from last found postion

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 239 ms faster than: 35.34%
   Memory Usage: 12.9 MB less than: 52.56%
   Remarks:
*/

class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        if (nums.size() < 3) {
            return count;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; j++) {
                while (k < nums.size() && (nums[i] + nums[j]) > nums[k]) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};