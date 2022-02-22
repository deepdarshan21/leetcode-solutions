#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        First find that element exists or not and then find its min and max index using seperate modified
        binary search

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 10 ms faster than: 58.25%
   Memory Usage: 13.6 MB less than: 65.27%
   Remarks:
*/

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, mid, high = nums.size() - 1;
        bool found = false;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                found = true;
                break;
            } else {
                if (nums[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (!found) {
            return {-1, -1};
        }
        int minLow = low, minMid, minHigh = mid, start;
        while (minLow <= minHigh) {
            minMid = minLow + (minHigh - minLow) / 2;
            if (nums[minMid] == target) {
                if (minMid == minLow) {
                    start = minLow;
                    break;
                } else {
                    if (nums[minMid - 1] != target) {
                        start = minMid;
                        break;
                    } else {
                        minHigh = minMid - 1;
                    }
                }

            } else {
                if (nums[minMid] > target) {
                    minHigh = minMid - 1;
                } else {
                    minLow = minMid + 1;
                }
            }
        }

        int maxLow = mid, maxMid, maxHigh = high, end;
        while (maxLow <= maxHigh) {
            maxMid = maxLow + (maxHigh - maxLow) / 2;
            if (nums[maxMid] == target) {
                if (maxMid == maxHigh) {
                    end = maxHigh;
                    break;
                } else {
                    if (nums[maxMid + 1] != target) {
                        end = maxMid;
                        break;
                    } else {
                        maxLow = maxMid + 1;
                    }
                }

            } else {
                if (nums[maxMid] > target) {
                    maxHigh = maxMid - 1;
                } else {
                    maxLow = maxMid + 1;
                }
            }
        }
        return {start, end};
    }
};