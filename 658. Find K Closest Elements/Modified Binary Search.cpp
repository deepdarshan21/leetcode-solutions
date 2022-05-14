#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Modified Binary Search
        Use binary search to find start element of required range. For implementing this we should
        first find mid and then check if from mid start range or not, by comparing arr[mid] with arr[mid+k]

   Edge Cases:
        1. If arr[mid]==arr[mid+k]
            => if (arr[mid]<x) then low=mid+1
               else high = mid-1;

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 52 ms faster than: 71.99%
   Memory Usage: 31 MB less than: 95.53%
   Remarks:
*/

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = -1;
        int low = 0, mid, high = arr.size() - k;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (arr[mid] == arr[mid + k])
                if (arr[mid] < x) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                    start = mid;
                }
            else {
                if ((mid + k) < arr.size() && abs(arr[mid] - x) <= abs(arr[mid + k] - x)) {
                    high = mid - 1;
                    start = mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (start == -1) {
            start = arr.size() - k;
        }
        return vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};