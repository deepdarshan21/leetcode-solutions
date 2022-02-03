#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Naive
       Just add the two vectors and then sort them

   Edge Cases:
       

   Time Complexity: O((m+n)*log(m+n)) Space: O(m+n)
*/

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int len;
        len = nums1.size();
        double ans;
        if (len % 2 == 1) {
            ans = (nums1[((len + 1) / 2) - 1]);
        } else {
            ans = (double)((nums1[((len + 1) / 2) - 1]) + (nums1[((len + 1) / 2)])) / 2;
        }
        return ans;
    }
};