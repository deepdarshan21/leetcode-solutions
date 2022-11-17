#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 14 ms faster than: 14.05%
   Memory Usage: 11.3 MB less than: 13.84%
   Remarks:
*/

class Solution {
   public:
    vector<int> pancakeSort(vector<int>& arr) {
        priority_queue<int> pq(arr.begin(), arr.end());
        vector<int> res;
        int n = arr.size(), len = n;
        for (int i = 0; i < n; i++) {
            int temp = pq.top();
            pq.pop();
            int idx = 0;
            while (idx < n) {
                if (arr[idx] == temp) break;
                idx++;
            }
            res.push_back(idx + 1);
            reverse(arr.begin(), arr.begin() + idx + 1);
            res.push_back(len);
            reverse(arr.begin(), arr.begin() + len);
            len--;
        }
        return res;
    }
};