#include <bits/stdc++.h>
using namespace std;

/* 
    Approach: Brute Force
        Check every index from 0 for all elements of vector string.

    Time Complexity: O(n*l) 
    Space: O(1)        
*/

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        while (true) {
            if (strs[0].size() <= count) {
                break;
            }
            char temp = strs[0][count];
            bool isCompleted = true;
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].size() <= count || strs[i][count] != temp) {
                    isCompleted = false;
                    break;
                }
            }
            if (!isCompleted) {
                break;
            }
            count++;
        }
        return strs[0].substr(0, count);
    }
};