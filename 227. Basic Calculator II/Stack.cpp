#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math, Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 23 ms faster than: 34.67%
   Memory Usage: 8.7 MB less than: 49.13%
   Remarks:
*/

class Solution {
   public:
    int calculate(string s) {
        stack<int> num;
        int n = s.size();
        if (n == 0) return 0;
        int currNum = 0;
        char opr = '+';
        for (int i = 0; i < n; i++) {
            char currChar = s[i];
            if (isdigit(currChar))
                currNum = currNum * 10 + (currChar - 48);
            if (!isdigit(currChar) && !isspace(currChar) || i == n - 1) {
                if (opr == '-')
                    num.push(-currNum);
                else if (opr == '+')
                    num.push(currNum);
                else if (opr == '*') {
                    int temp = num.top();
                    num.pop();
                    num.push(temp * currNum);
                } else if (opr == '/') {
                    int temp = num.top();
                    num.pop();
                    num.push(temp / currNum);
                }
                opr = currChar;
                currNum = 0;
            }
        }
        int res = 0;
        while (!num.empty()) {
            res += num.top();
            num.pop();
        }
        return res;
    }
};