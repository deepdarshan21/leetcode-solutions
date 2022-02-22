#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priority Queue
        Store the nums array's element in a "priority_queue" with condition that if any element in 'nums'
        is odd then multiply that element by 2 and then store. Then just decrease the maximum element till
        it it becomes odd.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 273 ms faster than: 66.75%
   Memory Usage: 71.4 MB less than: 60.68%
   Remarks: Same thing can be done by "set" also.
*/

class Solution {
   public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> store;
        int minElement = INT_MAX;
        for (auto num : nums) {
            if (num % 2 == 1) {
                minElement = min(minElement, 2 * num);
                store.push(2 * num);
            } else {
                minElement = min(minElement, num);
                store.push(num);
            }
        }
        int minDiff = INT_MAX, maxElement;
        while (store.top() % 2 == 0) {
            maxElement = store.top();
            store.pop();
            minDiff = min(minDiff, maxElement - minElement);
            store.push(maxElement / 2);
            minElement = min(minElement, maxElement / 2);
        }
        minDiff = min(minDiff, store.top() - minElement);
        return minDiff;
    }
};