#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 453 ms faster than: 35%
   Memory Usage: 115.9 MB less than: 14%
   Remarks:
*/

class Solution {
   public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> arr(n + 1);
        arr[0] = 0;
        for (int i = 0; i < n; i++) arr[i + 1] = (long long)arr[i] - differences[i];
        int maxEle = *max_element(arr.begin(), arr.end());
        int minEle = *min_element(arr.begin(), arr.end());
        int res = ((upper - lower) - (maxEle - minEle) + 1);
        if (res <= 0) return res;
        return res;
    }
};