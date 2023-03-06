#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Linear Search

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 88.86%
   Memory Usage: 9.6 MB less than: 38.6%
   Remarks:
*/

class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, j = 0;
        while (k > 0 && j < arr.size()) {
            i++;
            if (i != arr[j])
                k--;
            else
                j++;
        }
        if (k == 0) return i;
        return i + k;
    }
};