#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DNF Sort(Two Pointer)
        DNF sort is a typing of sorting algo where we short 0, 1, 2 in an array.
        In this kind of sorting we take three pointers low, mid and high and intitialise them with
        0, 0 and nums.size()-1 respectivly.
        We then run the while loop till mid<=high
            In the loop we check if nums[mid]==0 => swap nums[low] with nums[mid] and increase low and mid by 1
                                 if nums[mid]==1 => Increase mid by 1
                                 if nums[mid]==2 => swap nums[high] with nums[mid] and decrease high by 1.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 58.20%
   Memory Usage: 8.4 MB less than: 25.30%
   Remarks:
*/

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            switch (nums[mid]) {
                case 0: {
                    swap(nums[low++], nums[mid++]);
                    break;
                }
                case 1: {
                    mid++;
                    break;
                }
                case 2: {
                    swap(nums[high--], nums[mid]);
                    break;
                }
            }
        }
    }
};