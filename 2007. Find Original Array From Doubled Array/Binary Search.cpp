#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: WIll fail in some cases as putting -1 makes the array unsorted;
*/

class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size(), m = changed.size();
        if (n % 2 == 1) return {};
        vector<int> res;
        sort(changed.begin(), changed.end());
        for (int i = 0; i < m / 2; i++) {
            if (changed[i] == -1) continue;
            int target = changed[i] * 2, low = i, high = n, mid;
            while (low < high) {
                mid = low + (high - low) / 2;
                if (changed[mid] == target)
                    break;
                else if (changed[mid] < target)
                    low = mid + 1;
                else
                    high = mid;
            }
            if (mid > i && mid < n) {
                // changed.erase(changed.begin() + mid);
                changed[mid] = -1;
                res.push_back(changed[i]);
                // n--;
            } else
                return {};
        }
        if (res.size() != m / 2) return {};
        return res;
    }
};