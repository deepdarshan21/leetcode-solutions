#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(min no. of pages)

   Edge Cases:

   Time Complexity: O(logn*(nlogn)) Space: O(1)
   Status: Accepted
   Runtime: 782 ms faster than: 12.11%
   Memory Usage: 96.8 MB less than: 53.52%
   Remarks:
*/

class Solution {
   public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        auto isPossible = [&](int check) {
            vector<int> temp(removable.begin(), removable.begin() + check);
            sort(temp.begin(), temp.end());

            int removeI = 0, pI = 0;
            for (int i = 0; i < s.size(); i++) {
                if (removeI < temp.size() && i == temp[removeI]) {
                    removeI++;
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
            if (isPossible(mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};