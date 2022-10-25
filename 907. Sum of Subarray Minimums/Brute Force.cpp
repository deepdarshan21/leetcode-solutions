#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        int res = 0, temp = INT_MAX;
        for (int i = 0; i < n; i++) {
            temp = INT_MAX;
            for (int j = 1; j < (n - i); j++) {
                temp = min(temp, arr[i + j - 1]);
                res = (res + temp) % mod;
            }
        }
        return res;
    }
};