#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        function<int(int, int)> rec = [&](int idx1, int idx2) {
            if (idx1 == n1) {
                int tmp = 0;
                for (int i = idx2; i < n2; i++) tmp += s2[i];
                return tmp;
            }
            if (idx2 == n2) {
                int tmp = 0;
                for (int i = idx1; i < n1; i++) tmp += s1[i];
                return tmp;
            }
            if (s1[idx1] == s2[idx2]) return rec(idx1 + 1, idx2 + 1);
            int res1, res2;
            // delete s1's char
            res1 = s1[idx1] + rec(idx1 + 1, idx2);
            // delete s2's char
            res2 = s2[idx2] + rec(idx1, idx2 + 1);
            return min(res1, res2);
        };

        return rec(0, 0);
    }
};