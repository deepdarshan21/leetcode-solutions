#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 83.78%
   Memory Usage: 9.1 MB less than: 49.04%
   Remarks:
*/

class Solution {
   public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if ((arr[i] - arr[i - 1]) != diff) {
                return false;
            }
        }
        return true;
    }
};