#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting and Binary Search

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 342 ms faster than: 59.53%
   Memory Usage: 73.6 MB less than: 47.42%
   Remarks:
*/

class Solution {
   public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(), nums1.end());
        int n = nums2.size();
        for (int i = 0; i < n; i++) {
            auto itr = *s.rbegin() <= nums2[i] ? s.begin() : s.upper_bound(nums2[i]);
            nums1[i] = *itr;
            s.erase(itr);
        }
        return nums1;
    }
};