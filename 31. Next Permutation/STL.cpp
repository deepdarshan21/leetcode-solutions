#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using Standard Templete Library
        STL has a "next_permutation" name function which returns next permutation or "false" if
        no further permutations are available

   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Accepted
   Runtime: 7 ms faster than: 51.27%
   Memory Usage: 12 MB less than: 75.23%
   Remarks:
*/

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        if (next_permutation(nums.begin(), nums.end()) == false) {
            sort(nums.begin(), nums.end());
        }
    }
};