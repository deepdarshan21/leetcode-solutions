#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Use map to store the freq

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 808 ms faster than: 51.46%
   Memory Usage: 167.8 MB less than: 81.81%
   Remarks:
*/

class Solution {
   public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        bool check1 = false, check2 = false;
        int res = 0;
        for (string word : words) {
            string temp = word;
            reverse(temp.begin(), temp.end());
            auto itr = mp.find(temp);
            if (itr != mp.end() && itr->second > 0) {
                check2 = true;
                res += 4;
                itr->second--;
                continue;
            }
            mp[word]++;
        }
        for (auto itr : mp) {
            string temp = itr.first;
            reverse(temp.begin(), temp.end());
            if (temp == itr.first) {
                if (check1 && itr.second % 2 == 1)
                    res += itr.second * 2 - 2;
                else {
                    if (itr.second % 2 == 1) {
                        res += itr.second * 2;
                        check1 = true;
                    } else
                        res += itr.second * 2;
                }
            }
        }
        if (!check1 && !check2) return 0;
        if (check2)
            return res;
        return 2;
    }
};