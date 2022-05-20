#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search

   Edge Cases:
        1. Set default value to 0 => if answer not found the return 0
   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 27 ms faster than: 41.04%
   Memory Usage: 18.7 MB less than: 47.43%
   Remarks:
*/

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int low = 1, mid, high = citations.size();
        int res = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (citations[mid - 1] >= mid) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};