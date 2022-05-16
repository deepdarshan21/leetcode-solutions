#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashing(Counting Sort)
        First count the freq of all the three colors and then print them in order till there freq
        becomes zero.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 8.3 MB less than: 71.16%
   Remarks:
*/

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        vector<int> store(3, 0);
        for (int i = 0; i < nums.size(); i++) {
            store[nums[i]]++;
        }
        int i = 0, j = 0;
        while (j < 3 && i < nums.size()) {
            if (store[j] == 0) {
                j++;
                continue;
            }
            nums[i] = j;
            store[j]--;
            i++;
        }
    }
};