#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(min no. of pages) + Hasing

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 462 ms faster than: 23.83%
   Memory Usage: 95 MB less than: 54.30%
   Remarks: Use hasing to reduce time complexity at some cost of space
*/

class Solution {
   public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        auto isPossible = [&](string s, int check) {
            for (int i = 0; i < check; i++) {
                s[removable[i]] = '*';
            }

            int pI = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '*') {
                    continue;
                }
                if (s[i] == p[pI]) {
                    pI++;
                }
                if (pI == p.size()) {
                    return true;
                }
            }

            return false;
        };
        int low = 0, mid, high = removable.size();
        int res = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(s, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};