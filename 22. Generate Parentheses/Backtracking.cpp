#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Backtracking


   Edge Cases:


   Time Complexity: O(2^n) Space: O(2^n)
   Status: Accepted
   Runtime: 4 ms faster than: 73.67%
   Memory Usage: 13.7 MB less than: 47.21%
*/

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0, "");
        return possibleCombinations;
    }

   private:
    vector<string> possibleCombinations;
    void backtrack(int n, int op, int cp, string curr) {
        if (op == n && cp == n) {
            possibleCombinations.push_back(curr);
            return;
        }
        if (op < n) {
            backtrack(n, op + 1, cp, curr + "(");
        }
        if (cp < op) {
            backtrack(n, op, cp + 1, curr + ")");
        }
    }
};