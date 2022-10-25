#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(2)
   Status: Accepted
   Runtime: 7 ms faster than: 15.19%
   Memory Usage: 7.9 MB less than: 56.23%
   Remarks:
*/

class Solution {
   public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> res;
        int i = 1, idx = 0;
        while (idx < len) {
            res.push_back("Push");
            if (i == target[idx]) {
                i++;
                idx++;
                continue;
            }
            res.push_back("Pop");
            i++;
        }
        return res;
    }
};