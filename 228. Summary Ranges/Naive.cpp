#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Linear Search

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7 MB less than: 14%
   Remarks:
*/

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.size() == 0) {
            return ranges;
        }
        int start, end;
        start = nums[0];
        end = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (nums[i - 1] + 1)) {
                end = nums[i];
            } else {
                string range = "";
                if (end > start) {
                    range += to_string(start) + "->" + to_string(end);
                    ranges.push_back(range);
                    start = nums[i];
                } else {
                    range = to_string(start);
                    ranges.push_back(range);
                    start = nums[i];
                }
            }
        }
        string range = "";
        if (end > start) {
            range += to_string(start) + "->" + to_string(end);
            ranges.push_back(range);
        } else {
            range = to_string(start);
            ranges.push_back(range);
        }
        return ranges;
    }
};