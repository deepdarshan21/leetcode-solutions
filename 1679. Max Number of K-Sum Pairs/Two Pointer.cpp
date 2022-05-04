#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sort then Two Pointer

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 241 ms faster than: 28.04%
   Memory Usage: 58.2 MB less than: 62.65%
   Remarks:
*/

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if ((nums[start] + nums[end]) == k) {
                res++;
                start++;
                end--;
            } else {
                if ((nums[start] + nums[end]) > k) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return res;
    }
};