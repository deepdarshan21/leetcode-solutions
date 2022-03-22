#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 43 ms faster than: 79.65%
   Memory Usage: 27.1 MB less than: 35.89%
   Remarks:
*/

class Solution {
   public:
    string getSmallestString(int n, int k) {
        string s = "";
        n = n * 26;
        while (k > 0) {
            if (n - k >= 26) {
                s.push_back('a');
                n -= 26;
                k--;
            } else {
                s.push_back(96 + 26 - (n - k));
                k -= 26 - (n - k);
                break;
            }
        }
        while (k > 0) {
            if (k > 26) {
                s.push_back('z');
                k -= 26;
            } else {
                s.push_back(96 + k);
                k = 0;
            }
        }
        return s;
    }
};