#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        First make the "startSort" vector pair to store the element and its corrosponding index and
        then sort that vector according to element in it => usefull in appling BS

        The  again run loop on "intervals" vector to take end of every interval and then apply BS
        to find the best interval

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 102 ms faster than: 48.57%
   Memory Usage: 27.9 MB less than: 55.38%
   Remarks:
*/

class Solution {
   public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startStore;
        for (int i = 0; i < intervals.size(); i++) {
            startStore.push_back({intervals[i][0], i});
        }
        sort(startStore.begin(), startStore.end());
        vector<int> res;
        for (auto interval : intervals) {
            int low = 0, mid, high = startStore.size() - 1;
            int bestPos = -1;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (startStore[mid].first >= interval[1]) {
                    bestPos = startStore[mid].second;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            res.push_back(bestPos);
        }
        return res;
    }
};