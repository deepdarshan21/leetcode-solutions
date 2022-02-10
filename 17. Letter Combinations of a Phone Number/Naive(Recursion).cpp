#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using Recursion


   Edge Cases:
        1. If size of "digits" is 0

   Time Complexity: O(a^n) Space: O(a^n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7.1 MB less than: 7.39%
*/

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        recursion(digits, 0, "");
        return possibleCombinations;
    }

   private:
    vector<string> possibleCombinations;
    void recursion(string digit, int pos, string tillNow) {
        vector<string> store({"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        if (pos >= digit.size()) {
            // push tillNow to possibleCombinations
            possibleCombinations.push_back(tillNow);
            return;
        }
        for (int i = 0; i < store[digit[pos] - 48 - 2].size(); i++) {
            recursion(digit, pos + 1, tillNow + store[digit[pos] - 48 - 2][i]);
        }
    }
};