#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Use Binary search to find correct partition
       

   Edge Cases:
       1. If left hand partition is of length 0
       2. If right hand partition is of lenght 0

   Time Complexity: O(log(n)) Space: O(1)
        where, n is the size of the smallest vector
*/

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1, n2, low, high, cut1, cut2, l1, l2, h1, h2;
        n1 = nums1.size();
        n2 = nums2.size();
        low = 0;
        high = n1;

        while (low <= high) {
            cut1 = low + (high - low) / 2;
            cut2 = (n1 + n2 + 1) / 2 - cut1;  // total half - first half

            // edge cases
            l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
            l2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);
            h1 = (cut1 == n1 ? INT_MAX : nums1[cut1]);
            h2 = (cut2 == n2 ? INT_MAX : nums2[cut2]);

            if (l1 <= h2 && l2 <= h1) {
                if ((n1 + n2) % 2 == 0) {
                    return ((max(l1, l2) + min(h1, h2)) / 2.0);
                } else {
                    return (max(l1, l2) / 1.0);
                }
            } else if (l1 > h2) {
                high = cut1 - 1;
            } else if (l2 > h1) {
                low = cut1 + 1;
            }
        }
        return 0;
    }
};