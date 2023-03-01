#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Merge Sort


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 470 ms faster than: 26%
   Memory Usage: 133.4 MB less than: 19.4%
   Remarks:
*/

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        auto mergeSort = [&](auto&& self, int l, int r) -> void {
            if (l >= r) return;
            int mid = (l + r) / 2;
            self(self, l, mid);
            self(self, mid + 1, r);
            int i = l, j = mid + 1, k = 0;
            vector<int> temp(r - l + 1);
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    temp[k++] = nums[i++];
                } else {
                    temp[k++] = nums[j++];
                }
            }
            while (i <= mid) temp[k++] = nums[i++];
            while (j <= r) temp[k++] = nums[j++];
            for (int i = l; i <= r; i++) nums[i] = temp[i - l];
        };
        mergeSort(mergeSort, 0, n - 1);
        return nums;
    }
};