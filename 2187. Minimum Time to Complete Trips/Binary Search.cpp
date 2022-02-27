#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Find possible number of trip on a given time and minimise it.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 412 ms faster than: 68.42%
   Memory Usage: 262.8 MB less than: 31.58%
   Remarks:
*/

class Solution {
   public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = 1e14, mid;
        long long minTime;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(time, mid, totalTrips)) {
                minTime = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minTime;
    }

   private:
    bool isPossible(vector<int> time, long long timeTaken, int totalTrip) {
        long long currTrip = 0;
        for (auto& t : time) {
            currTrip += timeTaken / t;
            if (currTrip >= totalTrip) {
                return true;
            }
        }
        return currTrip >= totalTrip;
    }
};