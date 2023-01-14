#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 11 ms faster than: 80.70%
   Memory Usage: 7.7 MB less than: 50.48%
   Remarks:
*/

class Solution {
   public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> arr(n);
        arr[0] = 1;
        int t1 = 0, t2 = 0, t3 = 0;
        for (int i = 1; i < n; i++) {
            arr[i] = min({arr[t1] * 2, arr[t2] * 3, arr[t3] * 5});
            if (arr[i] == (arr[t1] * 2)) t1++;
            if (arr[i] == (arr[t2] * 3)) t2++;
            if (arr[i] == (arr[t3] * 5)) t3++;
        }
        return arr[n - 1];
    }
};