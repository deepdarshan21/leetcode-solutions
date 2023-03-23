#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: It is not concidering starting letter missmatch issue
*/

class Solution {
   public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        string str1 = "", str2 = "";
        for (int i = 0; i < n1; i++) str1 += s1;
        for (int i = 0; i < n2; i++) str2 += s2;

        int i = 0, j = 0;
        while (j < s2.size()) {
            if (str1[i] == str2[j]) j++;
            i++;
        }
        return str1.size() / i;
    }
};