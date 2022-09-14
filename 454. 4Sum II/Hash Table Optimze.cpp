#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hash Table
        First modify the target as target-nums1[i]-nums2[j] and then use hashmap to get that value in O(1)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 388 ms faster than: 54.24%
   Memory Usage: 24.4 MB less than: 54.77%
   Remarks:
*/

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0, n = nums1.size();
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ump[nums3[i] + nums4[j]]++;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                count += ump[0 - (nums1[i] + nums2[j])];
            }
        }
        return count;
    }
};