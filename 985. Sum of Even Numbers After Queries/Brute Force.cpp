#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        First make a sum all even numbers and then modify that sum


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 287 ms faster than: 10.72%
   Memory Usage: 49.7 MB less than: 20.44%
   Remarks:
*/

class Solution {
   public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for (int num : nums)
            if (num % 2 == 0) sum += num;
        for (auto itr : queries) {
            int temp = nums[itr[1]];
            nums[itr[1]] += itr[0];
            if (temp % 2 == 0) {
                if (itr[0] % 2 == 0)
                    sum += itr[0];
                else
                    sum -= temp;
            } else {
                if (itr[0] % 2 == 1 || itr[0] % 2 == -1) sum += nums[itr[1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};