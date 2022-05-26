#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        First make a array to store the sum from start to that index in nums
        Then use that array in making of new "subArr" array, where we will store the sum of all the
        subarrays;
        Now sort the "subArr"
        Finally, find the sum from left to right in parallel mod the sum too.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 159 ms faster than: 67.95%
   Memory Usage: 23.7 MB less than: 60.54%
   Remarks:
*/

class Solution {
   public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> store;
        store.push_back(0);
        int temp = 0;
        for (auto num : nums) {
            store.push_back(store[temp++] + num);
        }
        vector<int> subArr;
        for (int i = 1; i < store.size(); i++) {
            for (int j = i; j < store.size(); j++) {
                subArr.push_back(store[j] - store[i - 1]);
            }
        }
        sort(subArr.begin(), subArr.end());
        int sum = 0;
        for (int i = left - 1; i < right; i++) {
            sum = (sum + subArr[i]) % 1000000007;
        }
        return sum;
    }
};