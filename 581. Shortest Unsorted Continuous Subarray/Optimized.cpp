#include <bits/stdc++.h>
using namespace std;

/*
   Approach:
        First find intial start and intial end by camparing with neighbors and then find the
        final start and final end by the help of max and min element between intial start and intial end

   Edge Cases:
        1. if nums size is 1 => nums.size() return value in unsigned interger

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 39 ms faster than: 64.19%
   Memory Usage: 26.6 MB less than: 68.90%
   Remarks:
*/

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start, end;
        for (start = 0; start < (int)(nums.size()) - 2; start++) {
            if (nums[start + 1] < nums[start]) {
                break;
            }
        }
        for (end = nums.size() - 1; end > 0; end--) {
            if (nums[end - 1] > nums[end]) {
                break;
            }
        }

        // cout<<start<<" intial "<<end<<endl;
        if (start > end) {
            return 0;
        }

        int max = *max_element(nums.begin() + start, nums.begin() + end + 1);
        int min = *min_element(nums.begin() + start, nums.begin() + end + 1);
        // cout<<min<<" min max "<<max<<endl;

        for (int i = 0; i < start; i++) {
            if (nums[i] > min) {
                start = i;
                break;
            }
        }
        for (int j = nums.size() - 1; j > end; j--) {
            if (nums[j] < max) {
                end = j;
                break;
            }
        }

        // cout<<start<<" final "<<end<<endl;
        return end - start <= 0 ? 0 : end - start + 1;
    }
};