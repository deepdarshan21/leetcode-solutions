#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sort the array first and if sum till that index of sorted array and main array same then increment answer by 1

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 24 ms faster than: 43.49%
   Memory Usage: 12.4 MB less than: 55.97%
   Remarks:
*/

class Solution {
   public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());
        long long res = 0, sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += sortedArr[i];
            sum2 += arr[i];
            if (sum1 == sum2) res++;
        }
        return res;
    }
};