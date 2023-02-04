#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n!) Space: O(1)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: It will take O(n!) time to generate all the permutations of s1 and check
            if s2 contains any of them.
*/

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        sort(s1.begin(), s1.end());
        do {
            if (s2.find(s1) != string::npos) return true;
        } while (next_permutation(s1.begin(), s1.end()));
        return false;
    }
};