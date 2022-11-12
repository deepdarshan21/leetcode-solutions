#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        sort based on positonal weight

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 8 ms faster than: 90.55%
   Memory Usage: 11.1 MB less than: 87.90%
   Remarks:
*/

class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        if (count(nums.begin(), nums.end(), 0) == nums.size()) return "0";
        sort(nums.begin(), nums.end(), [](int num1, int num2) {
            string a = to_string(num1), b = to_string(num2);
            return (a + b) >= (b + a);
        });
        string res = "";
        for (int num : nums) res += to_string(num);
        return res;
    }
};