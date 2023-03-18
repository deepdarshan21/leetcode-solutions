#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(bottom up)
        First calculate the maximum number of digits that can be formed with the given target.
        Then, start from the maximum number of digits and try to form the target with the maximum number of digits.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 20 ms faster than: 71.24%
   Memory Usage: 9.1 MB less than: 77.12%
   Remarks:
*/

class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> numOfDigits(target + 1);
        numOfDigits[0] = 0;

        for (int i = 1; i <= target; i++) {
            numOfDigits[i] = INT_MIN;
            for (int j = 0; j < 9; j++) {
                if (i >= cost[j]) {
                    numOfDigits[i] = max(numOfDigits[i], numOfDigits[i - cost[j]] + 1);
                }
            }
        }

        if (numOfDigits[target] < 0) return "0";

        string ans = "";
        for (int i = 8; i >= 0; i--) {
            while (target >= cost[i] && numOfDigits[target] == numOfDigits[target - cost[i]] + 1) {
                ans += (i + 1) + 48;
                target -= cost[i];
            }
        }

        return ans;
    }
};