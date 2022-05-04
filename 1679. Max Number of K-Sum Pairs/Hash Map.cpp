#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hash map

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 311 ms faster than: 12.49%
   Memory Usage: 67 .6 MB less than: 43.%
   Remarks:
*/

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> K;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            K[nums[i]]++;
        }
        for (auto itr : K) {
            if (itr.first == (k - itr.first)) {
                res += itr.second / 2;
            } else {
                if (K.find(k - itr.first) != K.end()) {
                    res += min(itr.second, K[k - itr.first]);
                    K[k - itr.first] = 0;
                }
            }
        }
        return res;
    }
};