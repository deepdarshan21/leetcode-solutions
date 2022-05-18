#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(min no. of pages)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 287 ms faster than: 88.99%
   Memory Usage: 101.6 MB less than: 45.24%
   Remarks:
*/

class Solution {
   public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        auto isPossible = [&](int check) {
            double count = 0.0;
            for (int i = 0; i < dist.size(); i++) {
                count = ceil(count);
                count += (double)dist[i] / check;
                if (count > hour) {
                    return false;
                }
            }
            return true;
        };

        int low = 1, mid, high = 10000000;
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