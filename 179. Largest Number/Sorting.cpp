#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Require the positional weight, which is not happing here
*/

class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        vector<vector<int>> newNum;
        for (int num : nums) {
            vector<int> temp;
            while (num != 0) {
                temp.insert(temp.begin(), num % 10);
                num /= 10;
            }
            newNum.push_back(temp);
        }
        sort(newNum.begin(), newNum.end(), [](vector<int> num1, vector<int> num2) {
            int i = 0;
            while (i < num1.size() && i < num2.size()) {
                if (num1[i] < num2[i])
                    return true;
                else if (num1[i] > num2[i])
                    return false;
                i++;
            }
            if (num1.size() != i) return num1[i] == 0;
            if (num2.size() != i) return num2[i] != 0;
            return false;
        });
        reverse(newNum.begin(), newNum.end());
        string res = "";
        for (auto itr : newNum) {
            for (int num : itr) {
                res += to_string(num);
            }
            // cout<<endl;
        }
        return res;
    }
};