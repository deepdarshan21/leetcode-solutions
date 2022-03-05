#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.2 MB less than: 15.09%
   Remarks:
*/

class Solution {
   public:
    string interpret(string command) {
        string res = "";
        for (int i = 0; i < command.size(); i++) {
            if (command[i] = 'G') {
                res += "G";
            } else {
                if (command[i + 1] == ')') {
                    res += "o";
                    i++;
                } else {
                    res += "al";
                    i += 3;
                }
            }
        }
        return res;
    }
};