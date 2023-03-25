#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(nlogn)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        function<void(int)> primeFactors = [&](int idx) {
            int i = 2;
            int n = nums[idx];
            while (n > 1) {
                if (n % i == 0) {
                    mp[i] = idx;
                    n /= i;
                } else {
                    i++;
                }
            }
        };

        function<set<int>(int)> returnPrimeFactors = [&](int n) {
            int i = 2;
            set<int> st;
            while (n > 1) {
                if (n % i == 0) {
                    st.insert(i);
                    n /= i;
                } else {
                    i++;
                }
            }
            return st;
        };

        for (int i = 0; i < n; i++) primeFactors(i);

        int i = 0, result = 0;
        while (i <= result) {
            set<int> tmp = returnPrimeFactors(nums[i]);
            for (int itr : tmp) {
                result = max(result, mp[itr]);
            }
            i++;
        }
        if (result == n - 1) return -1;
        return result;
    }
};