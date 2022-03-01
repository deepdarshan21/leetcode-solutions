#include <bits/stdc++.h>
using namespace std;

/*
   Approach: STL "__builtin_popcount"
        C++ STL has a function "builtin_popcount" to count number of 1's in binary of a given number

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 88.16%
   Memory Usage: 8.6 MB less than: 21.58%
   Remarks:
*/

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};