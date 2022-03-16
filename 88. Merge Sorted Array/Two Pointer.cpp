#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer
        Put the elements in nums1 from end

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 6 ms faster than: 27.56%
   Memory Usage: 9.1 MB less than: 72.96%
   Remarks:
*/

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = nums1.size() - 1; i >= 0; i--) {
            if (n < 1 || (m > 0 && n > 0 && nums1[m - 1] > nums2[n - 1])) {
                nums1[i] = nums1[m - 1];
                m--;
            } else {
                nums1[i] = nums2[n - 1];
                n--;
            }
        }
    }
};
