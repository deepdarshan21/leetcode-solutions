#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0LL;
        unordered_map<string, bool> store;
        int n = ideas.size();
        for (string idea : ideas) store[idea] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (ideas[i][0] == ideas[j][0]) continue;
                string ideaA = ideas[i], ideaB = ideas[j];
                ideaA[0] = ideas[j][0];
                ideaB[0] = ideas[i][0];
                if (store[ideaA] == false && store[ideaB] == false) {
                    res++;
                }
            }
        }
        return res;
    }
};