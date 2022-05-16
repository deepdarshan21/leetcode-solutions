#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Min no. of pages)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 337 ms faster than: 20.82%
   Memory Usage: 57.7 MB less than: 41.16%
   Remarks:
*/

class Solution {
   public:
    int maxDistance(vector<int>& position, int m) {
        int low = 1, mid, high = *max_element(position.begin(), position.end());
        int res;
        sort(position.begin(), position.end());

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(position, mid, m)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }

   private:
    bool isPossible(vector<int>& position, int mid, int m) {
        int last;
        last = position[0];
        m--;
        for (int i = 1; i < position.size(); i++) {
            if ((position[i] - last) >= mid) {
                last = position[i];
                m--;
            }
            if (m == 0) {
                return true;
            }
        }
        return false;
    }
};