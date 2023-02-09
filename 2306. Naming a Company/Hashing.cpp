#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashing
        Used a vector of unordered_set to store all the strings that start with
        the same letter. Then, for each pair of sets, we find the number of mutual
        strings, and add the number of distinct strings to the result.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 583 ms faster than: 82.93%
   Memory Usage: 83.5 MB less than: 39.2%
   Remarks:
*/

class Solution {
   public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        vector<unordered_set<string>> store(26);
        for (string idea : ideas)
            store[idea[0] - 'a'].insert(idea.substr(1));

        long long res = 0LL;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                // find number of mutual string in store[i] and store[j]
                int mutual = 0;
                for (string s : store[i]) {
                    if (store[j].count(s) >= 1) mutual++;
                }
                res += 2 * (store[i].size() - mutual) * (store[j].size() - mutual);
            }
        }
        return res;
    }
};