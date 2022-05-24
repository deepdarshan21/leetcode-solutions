#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search
        First make the vector pair to store difficulty and its corresponding profit and then modify
        that according to question(best profit for a difficulty)

        Then apply the BS to find profit for each worker

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 79 ms faster than: 87.41%
   Memory Usage: 37.6 MB less than: 64.57%
   Remarks:
*/

class Solution {
   public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> diffPorfitBest;
        for (int i = 0; i < difficulty.size(); i++) {
            diffPorfitBest.push_back({difficulty[i], profit[i]});
        }
        sort(diffPorfitBest.begin(), diffPorfitBest.end());
        for (int i = 1; i < diffPorfitBest.size(); i++) {
            if (diffPorfitBest[i].second < diffPorfitBest[i - 1].second) {
                diffPorfitBest[i].second = diffPorfitBest[i - 1].second;
            }
        }

        int res = 0;

        for (auto itr : worker) {
            int low = 0, mid, high = diffPorfitBest.size() - 1;
            int prof = 0;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (diffPorfitBest[mid].first <= itr) {
                    prof = diffPorfitBest[mid].second;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            res += prof;
        }

        return res;
    }
};