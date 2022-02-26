#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 28.54%
   Memory Usage: 7.1 MB less than: 45.14%
   Remarks:
*/

class Solution {
   public:
    double average(vector<int>& salary) {
        int sum, size;
        size = salary.size();
        sum = accumulate(salary.begin(), salary.end(), 0);
        sum -= *min_element(salary.begin(), salary.end());
        sum -= *max_element(salary.begin(), salary.end());
        return (1.0 * sum) / (size - 2);
    }
};