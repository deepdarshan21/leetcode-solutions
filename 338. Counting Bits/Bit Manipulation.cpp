#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation
        "&"-> Binary AND operator
        if n-> xxx1000...
        then n-1 -> xxx0111...
        so, binary AND of n and n-1 (n & (n-1)) is xxx0000
        Repeating this thing will give total number of "1" in given binary number

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 95.58%
   Memory Usage: 8.4 MB less than: 34.00%
   Remarks:
*/

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int noOf1 = 0, temp;
        for (int i = 0; i <= n; i++) {
            noOf1 = 0;
            temp = i;
            while (temp != 0) {
                noOf1++;
                temp &= (temp - 1);
            }
            ans.push_back(noOf1);
        }
        return ans;
    }
};