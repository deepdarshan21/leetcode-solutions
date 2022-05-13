#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        First sort the array, then use 2 for loops for first and second element, and then use binary
        search to count the element who's smaller then the sum of first two elements

   Edge Cases:
        1. If nums size is less then 3, this is because nums.size return unsigned bit
            => in the start of program add a if condition to check if array's size is smaller then 3

   Time Complexity: O(n^2^logn) Space: O(1)
   Status: Accepted
   Runtime: 1013 ms faster than: 6.53%
   Memory Usage: 13 MB less than: 5.57%
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
            for (int j = i + 1; j < nums.size() - 1; j++) {
                int pos = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
                // cout<<pos<<endl;
                if (pos > j) {
                    count += pos - 1 - j;
                }
            }
        }
        return count;
    }
};