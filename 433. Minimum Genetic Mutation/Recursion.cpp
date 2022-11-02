#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Not pass in all the cases
*/

class Solution {
   public:
    int minMutation(string start, string end, vector<string> &bank) {
        return help(start, end, bank, 0);
    }

   private:
    int help(string &start, string &end, vector<string> &bank, int i) {
        if (i >= 8) return 0;
        // cout << i << endl;
        if (start[i] == end[i]) {
            return help(start, end, bank, i + 1);
        } else {
            // cout << i << " " << start << " " << end;
            // cout << endl;
            char temp = start[i];
            start[i] = end[i];
            if (find(bank.begin(), bank.end(), start) != bank.end()) {
                return 1 + help(start, end, bank, i + 1);
            }
            start[i] = temp;
            int res = help(start, end, bank, i + 1);
            // cout << i << " " << start << " " << end;
            // cout << endl;
            start[i] = end[i];
            if (find(bank.begin(), bank.end(), start) != bank.end() && res > 0) {
                return 1 + res;
            }
        }
        return -1;
    }
};