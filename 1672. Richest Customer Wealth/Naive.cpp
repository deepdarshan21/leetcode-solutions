#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Calulate the wealth of each person and find maximum among them

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 87.00%
   Memory Usage: 8.1 MB less than: 10.68%
   Remarks:
*/

class Solution {
   public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (auto person : accounts) {
            maxWealth = max(maxWealth, accumulate(person.begin(), person.end(), 0));
        }
        return maxWealth;
    }
};