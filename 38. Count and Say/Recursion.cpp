#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion


   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 8 ms faster than: 75.13%
   Memory Usage: 6.6 MB less than: 78.78%
   Remarks:
*/

class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string res;
        res = countAndSay(n - 1);
        string ans = "";
        int count = 1;
        char check = res[0];
        for (int i = 1; i < res.size(); i++) {
            if (res[i] == check) {
                count++;
            } else {
                ans += to_string(count);
                ans.push_back(check);
                check = res[i];
                count = 1;
            }
        }
        ans += to_string(count);
        ans.push_back(check);
        return ans;
    }
};