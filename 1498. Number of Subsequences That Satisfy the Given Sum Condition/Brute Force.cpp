#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Make every possible subsequence and check and add;

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int numSubseq(vector<int>& nums, int target) {
        int count = 0;
        const int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        for (int min = 0; min < nums.size(); min++) {
            for (int max = min; max < nums.size(); max++) {
                if ((nums[min] + nums[max]) <= target) {
                    if (min == max) {
                        count = (count + 1) % mod;
                    } else {
                        int temp = 1;
                        for (int i = 0; i < (max - min - 1); i++) {
                            temp = (temp * 2) % mod;
                        }
                        count = (count + temp) % mod;
                    }
                } else {
                    if (min == max) {
                        break;
                    }
                }
            }
        }
        return count;
    }
};