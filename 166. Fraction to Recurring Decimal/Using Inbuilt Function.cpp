#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(1) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.3 MB less than: 38.96%
   Remarks:
*/

class Solution {
   public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) ans += "-";
        numerator = abs(numerator);
        denominator = abs(denominator);
        ans += to_string((long long)numerator / denominator);
        long long rem = (long long)numerator % denominator;
        if (rem == 0) return ans;
        ans += ".";
        unordered_map<long long, int> store;
        while (rem != 0) {
            if (store.find(rem) != store.end()) {
                ans.insert(store[rem], "(");
                ans += ")";
                break;
            }
            store[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / denominator);
            rem %= denominator;
        }
        return ans;
    }
};