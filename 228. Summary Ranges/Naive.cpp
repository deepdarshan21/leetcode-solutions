#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Linear Search
        Use two variable "start" and "end" to store start and end of the range
        Intially store first element of "nums" in "start"
        Iterate on "nums" vector form element one
            if "current element of nums" is just greater that by "1" to "previous element of nums":
                    "end" equal to "current element of nums"
            else:
                    if "end" is greater than "start":
                            Store this range as '"start"->"end"'
                    else:
                            Store this range as '"start"'
                    "start" equal to "current element of nums"

   Edge Cases:
        1. Subtraction of two number may cause int overflow.
            use,  "nums[i] == (nums[i - 1] + 1)" to restrict it.

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