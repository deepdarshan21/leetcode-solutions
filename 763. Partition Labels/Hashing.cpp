#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Hashing
        First count the freq of each char in string two hashmaps, "main, sub". In second traverse
        subtract the freq of char from sub, if any of the freq of sub becomes 0 then check is it possible.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 85.70%
   Memory Usage: 7.1 MB less than: 10.11%
   Remarks:
*/

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        map<char, int> main, sub;
        vector<int> ans;
        int count = 0;
        for (auto itr : s) {
            main[itr]++;
            sub[itr]++;
        }
        for (auto itr : s) {
            sub[itr]--;
            count++;
            if (sub[itr] == 0) {
                bool isPossible = true;
                for (auto itr : main) {
                    if (itr.second != sub[itr.first]) {
                        if (sub[itr.first] != 0) {
                            isPossible = false;
                            break;
                        }
                    }
                }
                if (isPossible) {
                    ans.push_back(count);
                    count = 0;
                }
            }
        }
        return ans;
    }
};