#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 11 ms faster than: 33.37%
   Memory Usage: 10.3 MB less than: 46.90%
   Remarks:
*/

class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int signOfProduct = 1;
        for (auto num : nums) {
            if (num < 0) {
                signOfProduct *= -1;
            } else if (num == 0) {
                return 0;
            }
        }
        return signOfProduct;
    }
};