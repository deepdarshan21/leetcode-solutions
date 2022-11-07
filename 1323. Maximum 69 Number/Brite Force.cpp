#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Convert to vector

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.1 MB less than: 17.66%
   Remarks:
*/

class Solution {
   public:
    int maximum69Number(int num) {
        vector<int> nums;
        while (num != 0) {
            nums.push_back(num % 10);
            num /= 10;
        }
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 6) {
                nums[i] = 9;
                break;
            }
        }
        int res = 0;
        for (int x : nums) res = res * 10 + x;
        return res;
    }
};