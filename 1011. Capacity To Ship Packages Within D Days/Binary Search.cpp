#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(min no. of pages)


   Edge Cases:

   Time Complexity: O(nlof(n)) Space: O(1)
   Status: Accepted
   Runtime: 71 ms faster than: 57.86%
   Memory Usage: 45.5 MB less than: 5.48%
   Remarks:
*/

class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *min_element(weights.begin(), weights.end()), mid, high = accumulate(weights.begin(), weights.end(), 0);
        int minWeightPerDay = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isValid(weights, days, mid)) {
                minWeightPerDay = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minWeightPerDay;
    }

    int isValid(vector<int> weights, int days, int mid) {
        int dayCount = 1;
        int sum = 0;
        for (auto weight : weights) {
            sum += weight;
            if (sum > mid) {
                if (weight > mid) {
                    return false;
                }
                sum = weight;
                dayCount++;
            }
        }
        return dayCount <= days;
    }
};