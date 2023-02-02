#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 5.9 MB less than: 83.25%
   Remarks:
*/

class Solution {
   public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        vector<char> numToChar(n);
        for (int i = 0; i < n; i++) numToChar[i] = i + '1';
        string res = "";
        for (int i = 0; i < (n - 1); i++) {
            int index = (k - 1) / fact[n - i - 1];
            res += numToChar[index];
            numToChar.erase(numToChar.begin() + index);
            k -= index * fact[n - i - 1];
        }
        res += numToChar[0];
        return res;
    }
};