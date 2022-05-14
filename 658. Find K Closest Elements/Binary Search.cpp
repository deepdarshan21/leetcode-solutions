#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        First find the element greater than equal to x and then increase the range with two pointer

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status:Accepted
   Runtime: 74 ms faster than: 48.27%
   Memory Usage: 31 MB less than: 89.84%
   Remarks:
*/

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> res;
        int low = pos - 1, high = pos;
        while (k--) {
            if (high >= arr.size() || low >= 0 && (abs(arr[low] - x) <= abs(arr[high] - x))) {
                low--;
            } else {
                high++;
            }
        }
        return vector<int>(arr.begin() + low + 1, arr.begin() + high);
    }
};