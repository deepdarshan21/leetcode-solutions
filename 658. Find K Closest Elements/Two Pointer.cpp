#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer
        First, take low and high as 0 and arr.size()-1, and then decrease the high and increase low
        so high-low+1 become equal to k. For decreasing and increasing, use the condition that, which
        element better suits the required condition.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 88 ms faster than: 40.05%
   Memory Usage: 31.8 MB less than: 59.76%
   Remarks:
*/

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - 1;
        while ((high - low + 1) != k) {
            if (abs(arr[low] - x) <= abs(arr[high] - x)) {
                high--;
            } else {
                low++;
            }
        }
        vector<int> res;
        for (int i = low; i <= high; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};