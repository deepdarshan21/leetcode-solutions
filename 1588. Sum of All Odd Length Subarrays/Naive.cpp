#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Find sum of every possible subarray and add them to give answer.

   Edge Cases:

   Time Complexity: O(n^3) Space: O(1)
   Status: Accepted
   Runtime: 20 ms faster than: 8.98%
   Memory Usage: 8.3 MB less than: 81.05%
   Remarks:
*/

class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0, size;
        for (int i = 0; i < arr.size(); i++) {
            size = 1;
            while (i + size <= arr.size()) {
                sum += accumulate(arr.begin() + i, arr.begin() + i + size, 0);
                size += 2;
            }
        }
        return sum;
    }
};