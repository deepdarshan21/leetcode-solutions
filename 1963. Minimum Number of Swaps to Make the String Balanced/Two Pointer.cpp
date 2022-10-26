#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Not fulfill all cases like "[[[]]]][][]][[]]][[["
*/

class Solution {
   public:
    int minSwaps(string s) {
        int n = s.size(), low = 0, high = n - 1;
        int res = 0;
        while (low < high) {
            if (s[low] == '[' || (s[low] == ']' && low > 0 && s[low - 1] == '[')) {
                low++;
                continue;
            }
            if (s[high] == ']' || (s[high] == '[' && high < (n - 1) && s[high + 1] == ']')) {
                high--;
                continue;
            }
            swap(s[low], s[high]);
            low++;
            high--;
            res++;
        }
        return res;
    }
};