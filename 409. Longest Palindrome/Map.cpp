#include <bits/stdc++.h>
using namespace std;

/*
   Approach: First put element in map and then add even count elements and add odd count element by decrement 1


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.6 MB less than: 50%
   Remarks:
*/

class Solution {
   public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int res = 0;
        bool odd = false;
        for (auto itr : mp) {
            if (itr.second % 2 == 0)
                res += itr.second;
            else {
                odd = true;
                res += itr.second - 1;
            }
        }
        if (odd) res++;
        return res;
    }
};