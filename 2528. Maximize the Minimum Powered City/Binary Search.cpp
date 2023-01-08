#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 410 ms faster than: 75%
   Memory Usage: 66.5 MB less than: 87.5%
   Remarks:
*/

class Solution {
   public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<int> add(n, 0);
        auto isPossible = [&](long long mid) {
            fill(add.begin(), add.end(), 0);
            long long extraPower = k;
            long long powerTillNow = accumulate(stations.begin(), stations.begin() + r, 0LL);
            for (int i = 0; i < n; i++) {
                if ((i + r) < n) powerTillNow += stations[i + r] + add[i + r];
                if (powerTillNow < mid) {
                    long long needed = mid - powerTillNow;
                    if (needed > extraPower) return false;
                    extraPower -= needed;
                    int tmp = min(n - 1, i + r);
                    add[tmp] = needed;
                    powerTillNow += needed;
                }
                if ((i - r) >= 0) powerTillNow = powerTillNow - (stations[i - r] + add[i - r]);
            }
            return true;
        };
        long long low = 0, high = accumulate(stations.begin(), stations.end(), 0LL) + k, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low - 1;
    }
};