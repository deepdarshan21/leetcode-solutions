#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priority Queue

   Edge Cases:

   Time Complexity: O(klogn) Space: O(n)
   Status: Accepted
   Runtime: 718 ms faster than: 77.69%
   Memory Usage: 98.7 MB less than: 97%
   Remarks:
*/

class Solution {
   public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k > 0) {
            k--;
            int temp = pq.top();
            pq.pop();
            pq.push(temp - floor(temp / 2));
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};