#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priory Queue(min-heap)
        Use priory queue to add possible subarray sum in order.

   Edge Cases:

   Time Complexity: O(n*nlogn) Space: O(n)
   Status: Accepted
   Runtime: 165 ms faster than: 56.69%
   Memory Usage: 8 MB less than: 91.88%
   Remarks:
*/

class Solution {
   public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        int res = 0;
        for (int i = 0; i < right; i++) {
            auto temp = pq.top();
            pq.pop();
            if (i >= (left - 1)) {
                res = (res + temp.first) % (int)(1e9 + 7);
            }
            if (temp.second < (nums.size() - 1)) {
                pq.push({(nums[temp.second + 1] + temp.first), temp.second + 1});
            }
        }
        return res;
    }
};