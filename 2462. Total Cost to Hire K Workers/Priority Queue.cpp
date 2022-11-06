#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy(Priority Queue)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 372 ms faster than: 25%
   Memory Usage: 72.6 MB less than: 25%
   Remarks:
*/

class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size(), low = 0, high = n - 1, count = 0;
        int cand = candidates;
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> left, right;
        while (count < k) {
            while (left.size() < cand && low <= high) left.push(costs[low++]);
            while (right.size() < cand && low <= high) right.push(costs[high--]);
            int a = left.empty() ? INT_MAX : left.top();
            int b = right.empty() ? INT_MAX : right.top();
            if (a <= b) {
                res += (long long)a;
                left.pop();
            } else {
                res += (long long)b;
                right.pop();
            }
            count++;
        }
        return res;
    }
};