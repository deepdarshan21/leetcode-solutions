#include <bits/stdc++.h>
using namespace std;

/*
   Approach: HashSet
        Use sliding window to travese all possible string and then store that strings in visited set
        if a string is all ready present in set, it mean it is repeating

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 239 ms faster than: 12.73%
   Memory Usage: 20.1 MB less than: 79.86%
   Remarks:
*/

class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> visited, res;
        int n = s.size();
        for (int i = 0; i < (n - 9); i++) {
            string temp = s.substr(i, 10);
            if (visited.find(temp) == visited.end()) {
                visited.insert(temp);
            } else {
                res.insert(temp);
            }
        }
        vector<string> resVector(res.begin(), res.end());
        return resVector;
    }
};