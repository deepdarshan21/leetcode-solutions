#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion
        Check for every posibility using recusion

   Edge Cases:

   Time Complexity: O(2^n) Space: O(1)
   Status: Accepeted
   Runtime: 22 ms faster than: 5.89%
   Memory Usage: 8.6 MB less than: 49.91%
   Remarks:
*/

class Solution {
   public:
    vector<int> numsSameConsecDiff(int n, int k) {
        int num = 0;
        for (int i = 1; i < 10; i++) {
            num = i;
            help(num, k, n - 1);
        }
        return store;
    }

   private:
    vector<int> store;
    void help(int num, int k, int n) {
        if (n == 0) {
            store.push_back(num);
            return;
        }
        int lastDigit = num % 10;
        int tempNum;
        if ((lastDigit + k) < 10) {
            tempNum = num * 10;
            tempNum += lastDigit + k;
            help(tempNum, k, n - 1);
        }
        if (k != 0 && (lastDigit - k) >= 0) {
            tempNum = num * 10;
            tempNum += lastDigit + k;
            help(tempNum, k, n - 1);
        }
    }
};