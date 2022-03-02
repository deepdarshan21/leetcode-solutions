#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 46 ms faster than: 7.69%
   Memory Usage: 8.3 MB less than: 95.28%
   Remarks:
*/

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int len1, len2;
        len1 = nums1.size();
        len2 = nums2.size();
        bool find, isPushed;
        for (int i = 0; i < len1; i++) {
            find = false;
            isPushed = false;
            for (int j = 0; j < len2; j++) {
                if (nums1[i] == nums2[j]) {
                    find = true;
                }
                if (nums2[j] > nums1[i] && find == true) {
                    ans.push_back(nums2[j]);
                    isPushed = true;
                    break;
                }
            }
            if (isPushed == false) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};