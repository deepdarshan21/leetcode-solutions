#include <bits/stdc++.h>
using namespace std;

/*
   Approach: GCD concept
        GCD of two numbers is:
            1. If both are equal, then the GCD is the number itself
            2. If number1 is greater then number2 then the GCD is the GCD of number1-number2 and number2
            3. If number2 is greater then number1 then the GCD is the GCD of number1 and number2-number1

   Edge Cases:

   Time Complexity: O(N) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 61.25%
   Memory Usage: 8.4 MB less than: 26.7%
   Remarks:
*/

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        if (n == 0 || m == 0) return "";
        if (n == m && str1 == str2) return str1;
        if (n < m) return gcdOfStrings(str2, str1);
        if (str1.substr(0, m) != str2) return "";
        return gcdOfStrings(str1.substr(m), str2);
    }
};