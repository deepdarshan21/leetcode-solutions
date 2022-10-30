#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n*2) Space: O(1)
   Status: Accepted
   Runtime: 949 ms faster than: 19.05%
   Memory Usage: 14.6 MB less than: 24.45%
   Remarks:
*/

class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        for (int i = 0; i < (n - 1); i++) res[i] = *max_element(arr.begin() + i + 1, arr.end());
        return res;
    }
};