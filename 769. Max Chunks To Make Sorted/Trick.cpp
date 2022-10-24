#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math(observation)

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 27.36%
   Memory Usage: 7.2 MB less than: 76.39%
   Remarks:
*/

class Solution {
   public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int res = 0, leftMax = -1;
        for (int i = 0; i < n; i++) {
            leftMax = max(leftMax, arr[i]);
            if (leftMax == i) res++;
        }
        return res;
    }
};