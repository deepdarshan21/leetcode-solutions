#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        First append the string with large length so that we can remove duplicate string of small length
        afterward

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n^m)
   Status: Accepted
   Runtime: 852 ms faster than: 5.18%
   Memory Usage: 14.4 MB less than: 92.99%
   Remarks:
*/

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string s1, string s2) {
            return s1.length() > s2.length();
        });
        string res = "";
        for (string word : words) {
            if (res.find(word + "#") == string::npos) {
                res += word + "#";
            }
        }
        return res.length();
    }
};