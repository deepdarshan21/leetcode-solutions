#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window(Two Pointer)
        First take a hashmap to store freq of elements and "maxLen" and "maxFreq" variable to
        store maximum possible length and maximum possible frequency of an element in a subsequence.

        Then use two pointers "start" and "end". "start" for moving subsequence start point and "end"
        for moving end of subsequence.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 19 ms faster than: 43.35%
   Memory Usage: 7.2 MB less than: 13.56%
   Remarks:
*/

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        unordered_map<char, int> store;
        int maxFreq = 0;

        int start = 0;
        for (int end = 0; end < s.size(); end++) {
            store[s[end]]++;
            maxFreq = max(maxFreq, store[s[end]]);
            while ((end - start - maxFreq + 1) > k) {
                store[s[start]]--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};