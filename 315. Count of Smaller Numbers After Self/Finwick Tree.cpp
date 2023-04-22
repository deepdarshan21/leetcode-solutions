#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Index Tree

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 548 ms faster than: 73.55%
   Memory Usage: 112.6 MB less than: 75.46%
   Remarks:
*/

class Solution {
   public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> bit;
        unordered_map<int, int> modNums;
        int max;

        function<void(vector<int>)> modify = [&](vector<int> nums) {
            sort(nums.begin(), nums.end());
            int i = 1;
            for (int num : nums) {
                if (modNums.count(num) == 0) {
                    modNums[num] = i;
                    i++;
                }
            }
            max = i;
        };

        function<int(int)>
            sum = [&](int n) -> int {
            int sum = 0;
            while (n > 0) {
                sum += bit[n];
                n = n - (n & -n);
            }
            return sum;
        };
        function<void(int, int)> update = [&](int idx, int x) -> void {
            while (idx <= max) {
                bit[idx] += x;
                idx = idx + (idx & -idx);
            }
        };
        for (int i = n - 1; i >= 0; i--) {
            int tmp = modNums[nums[i]];
            nums[i] = sum(tmp - 1);
            update(tmp, 1);
        }
        return nums;
    }
};