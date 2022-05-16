#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Min no. of pages)


   Edge Cases:
        1. If piles' size is greater than total hours gaurd is out than it is not possible

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 46 ms faster than: 83.98%
   Memory Usage: 19 MB less than: 26.12%
   Remarks:
*/

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() > h) {
            return -1;
        }
        int low = 1, mid, high = *max_element(piles.begin(), piles.end()), res;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(piles, mid, h)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }

   private:
    bool isPossible(vector<int>& piles, int mid, int h) {
        int hourReq = 0;
        for (auto pile : piles) {
            if (pile % mid == 0) {
                hourReq += pile / mid;
            } else {
                hourReq += pile / mid + 1;
            }

            if (hourReq > h) {
                return false;
            }
        }
        return true;
    }
};