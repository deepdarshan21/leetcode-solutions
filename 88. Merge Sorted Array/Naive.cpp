#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Find the correct veccancy first then create the space for it thenn insert that element

   Edge Cases:
        1. All element of nums1 are traversed but remaining in nums2
   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 7 ms faster than: 21.79%
   Memory Usage: 9.1 MB less than: 72.99%
   Remarks:
*/

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while (m != 0 && n != 0) {
            if (nums1[i] > nums2[j]) {
                move(nums1, i);
                nums1[i] = nums2[j];
                i++;
                j++;
                n--;
            } else {
                i++;
                m--;
            }
        }
        while (n != 0) {
            nums1[i] = nums2[j];
            i++;
            j++;
            n--;
        }
    }

   private:
    void move(vector<int>& nums, int from) {
        for (int i = nums.size() - 1; i >= from + 1; i--) {
            nums[i] = nums[i - 1];
        }
    }
};