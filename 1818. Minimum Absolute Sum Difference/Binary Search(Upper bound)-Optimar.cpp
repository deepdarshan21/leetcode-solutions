#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Optimal)
        For each element find the best replacement, and subtract the maximum difference gentrated by
        best replacement.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 317 ms faster than: 29.43%
   Memory Usage: 74.8 MB less than: 6.16%
   Remarks: Revise karta rahna iss question ko.
*/

class Solution {
   public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> sortedNums1(nums1.begin(), nums1.end());

        int res = 0, minDiff, diff1, diff2, maxSave = 0;
        for (int i = 0; i < nums1.size(); i++) {
            res = (res + abs(nums1[i] - nums2[i])) % 1000000007;
            auto itr = sortedNums1.upper_bound(nums2[i]);
            diff1 = diff2 = INT_MAX;
            if (itr != sortedNums1.end()) {
                diff1 = abs(*itr - nums2[i]);
            }
            if (itr != sortedNums1.begin()) {
                diff2 = abs(*prev(itr) - nums2[i]);
            }
            minDiff = min(diff1, diff2);
            // cout<<minDiff<<" - ";
            // cout<<abs(nums1[i]-nums2[i])<<"("<<res<<")"<<" "<<minDiff<<" ";
            maxSave = max(maxSave, abs(abs(nums1[i] - nums2[i]) - minDiff));
            // cout<<maxSave<<endl;
        }
        return (1000000007 + res - maxSave) % 1000000007;
    }
};