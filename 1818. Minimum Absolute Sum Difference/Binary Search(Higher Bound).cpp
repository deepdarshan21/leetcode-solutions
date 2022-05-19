#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search(Upper Bound) + sorting
        First find the sum of difference at each index and correspodingly find the maxDiff and maxDiffI
        Then sort the array and find the index of element which is just greater then 'nums2[maxDiffI]'
        (upper bound) and then check that corrosponding to which "pos" or "pos-1" where we are getting
        min difference and for min difference find the answer.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: This kind of test case will give wrong answer in my this approach
        TEST CASE:nums1=[1,28,21], nums2=[9,21,20]
*/

class Solution {
   public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int maxDiff = INT_MIN, maxDiffI, sum = 0;
        for (int i = 0; i < nums1.size(); i++) {
            sum = (sum + abs(nums1[i] - nums2[i])) % 1000000007;
            if (maxDiff < abs(nums1[i] - nums2[i])) {
                maxDiff = abs(nums1[i] - nums2[i]);
                maxDiffI = i;
            }
        }
        sort(nums1.begin(), nums1.end());
        int pos = upper_bound(nums1.begin(), nums1.end(), nums2[maxDiffI]) - nums1.begin();
        if (pos == 0) {
            return sum - maxDiff + abs(nums1[pos] - nums2[maxDiffI]);
        }
        if (pos == nums1.size() || abs(nums1[pos - 1] - nums2[maxDiffI]) <= abs(nums1[pos] - nums2[maxDiffI])) {
            return sum - maxDiff + abs(nums1[pos - 1] - nums2[maxDiffI]);
        }
        return sum - maxDiff + abs(nums1[pos] - nums2[maxDiffI]);
    }
};