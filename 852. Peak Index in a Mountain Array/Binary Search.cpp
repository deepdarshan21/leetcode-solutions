#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Binary Search on Answer


   Edge Cases:

   Time Complexity: O(log(n)) Space: O(1)
   Status: Accepted
   Runtime: 13 ms faster than: 53.51%
   Memory Usage: 11.6 MB less than: 50.17%
   Remarks:
*/

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, mid, high = arr.size() - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if ((mid == 0 || arr[mid - 1] < arr[mid]) && (mid == arr.size() - 1 || arr[mid + 1] < arr[mid])) {
                return mid;
            } else {
                if (mid > 0 && arr[mid - 1] > arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};