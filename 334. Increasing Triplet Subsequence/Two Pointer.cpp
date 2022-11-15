#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting then two pointer

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> store;
        for (int i = 0; i < n; i++) store.push_back({nums[i], i});
        sort(store.begin(), store.end());
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (store[i].first < store[j].first && store[j].first < store[k].first && store[i].second < store[j].second && store[j].second < store[k].second) return true;
                if (store[i].first >= store[j].first || store[i].second > store[j].second)
                    j++;
                else
                    k--;
            }
        }
        return false;
    }
};