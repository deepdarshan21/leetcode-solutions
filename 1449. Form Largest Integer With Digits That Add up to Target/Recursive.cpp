#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(9^n) Space: O(n)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        auto rec = [&](auto self, int t) -> string {
            if (t == 0) return "";
            string ans = "0";
            for (int i = 0; i < 9; i++) {
                if (t >= cost[i]) {
                    string tmp = "";
                    tmp += (i + 1) + 48;
                    string temp = self(self, t - cost[i]);
                    if (temp == "0") continue;
                    tmp += temp;
                    // cout<<tmp<<endl;
                    if (stoll(tmp) > stoll(ans)) ans = tmp;
                }
            }
            return ans;
        };
        return rec(rec, target);
    }
};