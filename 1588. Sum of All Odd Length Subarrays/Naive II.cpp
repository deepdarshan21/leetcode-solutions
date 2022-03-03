#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Use store to store the sum of element in arr till that index.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 11 ms faster than: 24.44%
   Memory Usage: 8.5 MB less than: 7.55%
   Remarks:
*/

class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0, size;
        vector<int> sumStore(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0) {
                sumStore[i] = arr[i];
            } else {
                sumStore[i] = sumStore[i - 1] + arr[i];
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            size = 1;
            while (i + size <= arr.size()) {
                if (i == 0) {
                    sum += sumStore[i + size - 1];
                } else {
                    sum += sumStore[i + size - 1] - sumStore[i - 1];
                }
                size += 2;
            }
        }
        return sum;
    }
};