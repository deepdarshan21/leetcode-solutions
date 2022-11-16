#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Build the answer digit by digit, adding the largest possible one that would make the number
        still less than or equal to N.

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 7 ms faster than: 10.97%
   Memory Usage: 6 MB less than: 44.90%
   Remarks:
*/

class Solution {
   public:
    int monotoneIncreasingDigits(int n) {
        if (n == 0) return 0;
        string str = to_string(n);
        int n = str.size(), start = n;
        for (int i = n - 1; i > 0; i--) {
            if (str[i] < str[i - 1]) {
                start = i;
                str[i - 1]--;
            }
        }
        for (int i = start; i < n; i++) str[i] = '9';
        return stoi(str);
    }
};