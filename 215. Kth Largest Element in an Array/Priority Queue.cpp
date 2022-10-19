#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Min Heap

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 129 ms faster than: 87.63%
   Memory Usage: 47.13 MB less than: 32.19%
   Remarks:
*/

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int num : nums) {
            if (k > 0) {
                queue.push(num);
                k--;
            } else {
                if (num >= queue.top()) {
                    queue.pop();
                    queue.push(num);
                }
            }
        }
        return queue.top();
    }
};