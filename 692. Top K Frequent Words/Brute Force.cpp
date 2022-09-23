#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Wrong Answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: This solution is limited to k=2
*/

class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (string word : words) mp[word]++;
        int max1 = 0, max2 = 0;
        string str1 = "", str2 = "";
        for (auto itr : mp) {
            if (itr.second > max1) {
                max2 = max1;
                str2 = str1;
                max1 = itr.second;
                str1 = itr.first;
            } else if (itr.second > max2) {
                max2 = itr.second;
                str2 = itr.first;
            }
        }
        return {str1, str2};
    }
};