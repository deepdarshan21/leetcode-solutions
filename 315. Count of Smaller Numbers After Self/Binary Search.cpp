#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Maintain a seprate vector to store stored nums encounter till now by adding it to correct
        position. And use binary search to find the no. of element smaller than that element.

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Insert function take O(n) time which is causing TLE in extream test case
*/

class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0), sortedNums;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int idx = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
            res[i] = idx;
            sortedNums.insert(sortedNums.begin() + idx, nums[i]);
        }
        return res;
    }
};