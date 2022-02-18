#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        Try creating every posible number by removing 'k' digits from string.

   Edge Cases:

   Time Complexity: O(n^n) Space: O(n)
   Status: Runtime Error
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Given number's length is very large
*/

class Solution {
   public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        recursion(num, k);
        return to_string(min);
    }

   private:
    long long min = LLONG_MAX;
    void recursion(string num, int k) {
        if (k == 0 && min > stoi(num)) {
            min = stoi(num);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            string temp = "";
            temp += num.substr(0, i);
            temp += num.substr(i + 1, num.size() - i - 1);
            recursion(temp, k - 1);
        }
    }
};