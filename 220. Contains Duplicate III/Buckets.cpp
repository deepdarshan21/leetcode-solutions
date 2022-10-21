#include <bits/stdc++.h>
using namespace std;

/*
   Approach: https://leetcode.com/problems/contains-duplicate-iii/discuss/824578/C%2B%2B-O(N)-time-complexity-or-Explained-or-Buckets-or-O(K)-space-complexity

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 443 ms faster than: 34.34%
   Memory Usage: 74 MB less than: 62.92%
   Remarks:
*/

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        unordered_map<int, int> buckets;
        for (int i = 0; i < n; i++) {
            int bucket = nums[i] / (valueDiff + 1);
            if (nums[i] < 0) bucket--;
            if (buckets.find(bucket) != buckets.end()) return true;
            if (buckets.find(bucket - 1) != buckets.end() && abs(nums[i] - buckets[bucket - 1]) <= valueDiff) return true;
            if (buckets.find(bucket + 1) != buckets.end() && abs(nums[i] - buckets[bucket + 1]) <= valueDiff) return true;
            buckets[bucket] = nums[i];
            if (i >= indexDiff) {
                int remove = nums[i - indexDiff] / (valueDiff + 1);
                if (nums[i - indexDiff] < 0) remove--;
                buckets.erase(remove);
            }
        }
        return false;
    }
};