#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        Use the concept of infinite Binary Search to find the element which statisfies the given condition

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 196 ms faster than: 30.35%
   Memory Usage: 81.2 MB less than: 10.14%
   Remarks:
*/

class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if (chalk[0] > k) {
            return 0;
        }
        int low = 0, mid, high = 1;
        vector<long long int> sum(chalk.size());
        sum[0] = chalk[0];
        for (int i = 1; i < chalk.size(); i++) {
            sum[i] = sum[i - 1] + chalk[i];
        }
        while ((k - (high / (int)sum.size() * sum[sum.size() - 1] + sum[high % sum.size()])) >= 0) {
            low = high;
            high *= 2;
        }
        int res = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if ((k - mid / (int)sum.size() * sum[sum.size() - 1] - sum[mid % sum.size()]) < 0) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res % sum.size();
    }
};