#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> ump;
        for (int i = 0; i < nums4.size(); i++) {
            ump[nums4[i]]++;
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                for (int k = 0; k < nums3.size(); k++) {
                    count += ump[0 - (nums1[i] + nums2[j] + nums3[k])];
                }
            }
        }
        return count;
    }
};