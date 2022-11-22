#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Memorization

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 8.1 MB less than: 6.92%
   Remarks:
*/

class Solution {
   public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n <= 3) return *max_element(nums.begin(), nums.end());
        vector<int> arr1, arr2;
        for (int i = 0; i < (n - 1); i++) {
            arr1.push_back(nums[i]);
            // cout<<arr1.back()<<endl;
        }
        for (int i = 1; i < (n); i++) {
            arr2.push_back(nums[i]);
        }
        vector<int> dp1(n, -1), dp2(n, -1);
        int temp1 = max(help1(arr1.size() - 1, arr1, dp1), help1(arr1.size() - 2, arr1, dp1));
        int temp2 = max(help2(arr2.size() - 1, arr2, dp2), help2(arr2.size() - 2, arr2, dp2));
        // cout<<temp1<<" "<<temp2<<endl;
        return max(temp1, temp2);
    }
    int help1(int i, vector<int> &arr1, vector<int> &dp1) {
        if (i < 0) return 0;
        if (i <= 1) return arr1[i];
        if (dp1[i] != -1) return dp1[i];
        dp1[i] = arr1[i] + max(help1(i - 2, arr1, dp1), help1(i - 3, arr1, dp1));
        // cout<<i<<" "<<dp1[i]<<endl;
        return dp1[i];
    }
    int help2(int i, vector<int> &arr2, vector<int> &dp2) {
        if (i < 0) return 0;
        if (i <= 1) return arr2[i];
        if (dp2[i] != -1) return dp2[i];
        dp2[i] = arr2[i] + max(help2(i - 2, arr2, dp2), help2(i - 3, arr2, dp2));
        return dp2[i];
    }
};