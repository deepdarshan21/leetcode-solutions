#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 62%
   Memory Usage: 6 MB less than: 43.27%
   Remarks:
*/

class Solution {
   public:
    bool isNumber(string s) {
        int dot = 0, num = 0, e = 0, plus = 0, minus = 0, temp = 0, tmp = 0;
        for (int i = 0; i < s.size(); i++) {
            char x = s[i];
            if (isdigit(x)) {
                num++;
            } else if (x == 'e' || x == 'E') {
                if (e == 1) return false;
                e++;
                if (num == 0 && temp == 0) return false;
                if (i != 0 && (s[i - 1] == '-' || s[i] == '+')) return false;
                tmp = num;
                num = 0;
            } else if (x == '+') {
                if (dot == 1 && e != 1) return false;
                if (i != 0 && (s[i - 1] == 'e' || s[i - 1] == 'E')) continue;
                if (plus == 1 || minus == 1 && e != 1) return false;
                if (i != 0 && isdigit(s[i - 1])) return false;
                plus++;
            } else if (x == '-') {
                if (dot == 1 && e != 1) return false;
                if (plus == 1 || minus == 1) return false;
                if (i != 0 && isdigit(s[i - 1])) return false;
                minus++;
            } else if (x == '.') {
                if (dot == 1 || e == 1) return false;
                dot++;
                temp = num;
                num = 0;
            } else {
                return false;
            }
        }
        if (dot == 1 && num == 0 && temp == 0) return false;
        if (e == 1 && num == 0) return false;
        if (num == 0 && tmp == 0 && temp == 0) return false;
        return true;
    }
};