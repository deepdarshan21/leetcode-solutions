#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Min no. of pages)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 231 ms faster than: 45.87%
   Memory Usage: 63.3 MB less than: 25.91%
   Remarks:
*/

class Solution {
   public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        auto isPossible = [&](int check) {
            int count = 0;
            int temp = k;
            for (auto itr : bloomDay) {
                if (itr <= check) {
                    temp--;
                } else {
                    temp = k;
                }
                if (temp == 0) {
                    count++;
                    temp = k;
                }
                if (count == m) {
                    return true;
                }
            }
            return false;
        };

        if (bloomDay.size() < m * k) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end()), mid, high = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};