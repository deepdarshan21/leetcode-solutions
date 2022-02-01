#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Horizontal Scanning(Brute Force)
       Assume first as answer and then check the same with every other string.

   Edge Cases:
       

   Time Complexity: O(n*l)
   Space: O(1)
*/

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string commonPrifix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(commonPrifix) != 0) {
                commonPrifix = commonPrifix.substr(0, commonPrifix.size() - 1);
                if (commonPrifix.size() == 0) {
                    return "";
                }
            }
        }
        return commonPrifix;
    }
};
