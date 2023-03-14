#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(with maths)
        for n = 1, ans = 1
        for n = 2, ans = 2 * 3* 1(val of n = 1) = 6
        for n = 3, ans = 3 * 5 * 6(val of n = 2) = 90

   Edge Cases: for n = 1, ans = 1

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 63.67%
   Remarks:
*/

class Solution {
   public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long long ans = 1;
        for (int i = 2; i <= n; i++) ans = (i * (2 * i - 1) * ans) % mod;
        return ans;
    }
};