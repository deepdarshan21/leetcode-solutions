#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Quick Sort


   Edge Cases:

   Time Complexity: O(nlogn) Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        auto quickSort = [&](auto&& self, int l, int r) -> void {
            if (l >= r) return;
            int pivot = nums[r];
            int pi = (l - 1);

            for (int j = l; j < r; j++) {
                if (nums[j] < pivot) {
                    pi++;
                    swap(nums[pi], nums[j]);
                }
            }
            swap(nums[pi + 1], nums[r]);
            pi++;
            self(self, l, pi - 1);
            self(self, pi + 1, r);
        };
        quickSort(quickSort, 0, n - 1);
        return nums;
    }
};
