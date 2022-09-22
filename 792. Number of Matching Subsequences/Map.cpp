#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Unordered map
        First store the index of each char in a map of vector and then check is there exist a char whose
        index is greater then last elements index

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 649 ms faster than: 28.80%
   Memory Usage: 60.2 MB less than: 33.45%
   Remarks:
*/

class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> ump;
        for (int i = 0; i < s.size(); i++) ump[s[i]].push_back(i);
        int count = 0;
        unordered_map<string, bool> store;
        for (string word : words) {
            if (store.find(word) != store.end()) {
                if (store[word]) count++;
                continue;
            }
            int lastIdx = -1;
            bool isSubSequence = true;
            for (char x : word) {
                auto itr = upper_bound(ump[x].begin(), ump[x].end(), lastIdx);
                if (itr == ump[x].end()) {
                    isSubSequence = false;
                    break;
                }
                lastIdx = *itr;
            }
            if (isSubSequence) count++;
            store.insert({word, isSubSequence});
        }
        return count;
    }
};