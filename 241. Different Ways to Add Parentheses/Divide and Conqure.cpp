#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Divide and Conqure

   Edge Cases:

   Time Complexity: O(2^n) Space: O(n)
   Status: Accepted
   Runtime: 7 ms faster than: 32.59%
   Memory Usage: 11.2 MB less than: 54.63%
   Remarks:
*/

class Solution {
   public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left, right;
                left = diffWaysToCompute(expression.substr(0, i));
                right = diffWaysToCompute(expression.substr(i + 1, n));

                for (int l : left) {
                    for (int r : right) {
                        if (ch == '*')
                            res.push_back(l * r);
                        else if (ch == '-')
                            res.push_back(l - r);
                        else if (ch == '+')
                            res.push_back(l + r);
                    }
                }
            }
        }
        if (!res.size()) res.push_back(stoi(expression));
        return res;
    }
};