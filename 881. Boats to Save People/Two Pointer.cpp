#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Two Pointer
        First sort the array then use to pointer approach to check is it possible to take 2 person on
        a boat or not, accordingly increase the count of boats.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 151 ms faster than: 17.31%
   Memory Usage: 42 MB less than: 10.43%
   Remarks:
*/

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int low = 0, high = people.size() - 1;
        sort(people.begin(), people.end());
        while (low <= high) {
            if ((people[low] + people[high]) > limit) {
                count++;
                high--;
            } else {
                count++;
                high--;
                low++;
            }
        }
        return count;
    }
};