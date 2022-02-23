#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Iterative


   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepted
   Runtime: 7 ms faster than: 78.15%
   Memory Usage: 6.2 MB less than: 99.81%
   Remarks:
*/

class Solution {
   public:
    string countAndSay(int n) {
        string prev, curr;
        prev = "1";
        for (int i = 2; i <= n; i++) {
            curr = "";
            int count = 1;
            char check = prev[0];
            for (int i = 1; i < prev.size(); i++) {
                if (prev[i] == check) {
                    count++;
                } else {
                    curr += to_string(count);
                    curr.push_back(check);
                    check = prev[i];
                    count = 1;
                }
            }
            curr += to_string(count);
            curr.push_back(check);
            prev = curr;
        }
        return curr;
    }
};