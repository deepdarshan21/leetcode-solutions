#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Rverse Iteration

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 32 ms faster than: 65.56%
   Memory Usage: 14.6 MB less than: 24.45%
   Remarks:
*/

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int temp, greatestTillNow = -1, n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            temp = arr[i];
            arr[i] = greatestTillNow;
            greatestTillNow = max(greatestTillNow, temp);
        }
        return arr;
    }
};