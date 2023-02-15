#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 36 ms faster than: 42.41%
   Memory Usage: 27.1 MB less than: 99.31%
   Remarks:
*/

class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int m = to_string(k).size();
        vector<int> ans(max(n, m) + 1, 0);
        int i = n - 1, j = m - 1, carry = 0, len = max(n, m);
        while (i >= 0 || j >= 0 || carry) {
            int a = i >= 0 ? num[i] : 0;
            int b = j >= 0 ? k % 10 : 0;
            int sum = a + b + carry;
            ans[len] = sum % 10;
            carry = sum / 10;
            i--;
            j--;
            len--;
            k /= 10;
        }
        while (ans.size() > 1 && ans[0] == 0) ans.erase(ans.begin());
        return ans;
    }
};