#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Count for every second

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Think opposite
*/

class Solution {
   public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int t = 0;
        int sum = 0;
        while (sum < totalTrips) {
            sum = 0;
            for (int i = 0; i < time.size(); i++) {
                sum += t / time[i];
            }
            t++;
        }
        return t - 1;
    }
};