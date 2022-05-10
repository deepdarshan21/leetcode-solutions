#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window + Deque
        Apply normal sliding window, and use deque to handle negative number case😍

   Edge Cases:
        1. Integer overflow negative side, as the overall sum become less then 0 make it 0
        2. Integer overflow at positive side, as the sum become greater then remove elements
        from start of window so element can acumudate.

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 294 ms faster than: 65.40%
   Memory Usage: 101.2 MB less than: 96.54%
   Remarks:
*/

class Solution {
   public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long res = nums.size() + 1;
        deque<long long> store;
        for (long long i = 0; i < nums.size(); i++) {
            if (i > 0) {
                while ((INT_MAX - nums[i - 1]) < nums[i]) {
                    nums[i] -= nums[store.front()];
                    store.pop_front();
                }
                nums[i] += nums[i - 1];
            }
            if (nums[i] <= 0) {
                nums[i] = 0;
            }
            if (nums[i] >= k) {
                res = min(res, i + 1);
            }
            while (store.size() > 0 && (nums[i] - nums[store.front()]) >= k) {
                res = min(res, i - store.front()), store.pop_front();
            }
            while (store.size() && nums[i] <= nums[store.back()]) {
                store.pop_back();
            }
            store.push_back(i);
        }
        return res == nums.size() + 1 ? -1 : res;
    }
};