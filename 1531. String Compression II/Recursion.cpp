#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Recursion

   Edge Cases:

   Time Complexity: O(n*k) Space: O(log(n*k))
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int getLengthOfOptimalCompression(string s, int k) {
        vector<pair<char, int>> encoded;
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                count++;
            else {
                encoded.push_back({s[i - 1], count});
                count = 1;
            }
        }
        encoded.push_back({s[s.size() - 1], count});
        return help(encoded, k);
    }
    int help(vector<pair<char, int>> encoded, int k) {
        // for(auto itr: encoded){
        //     cout<<itr.first<<" "<<itr.second<<endl;
        // }
        // cout<<endl;
        if (k == 0) {
            int res = 0;
            char last = encoded[0].first;
            int lastFreq = encoded[0].second;
            for (auto itr = encoded.begin() + 1; itr != encoded.end(); itr++) {
                if (itr->second == 0) continue;
                if (last == itr->first) {
                    // cout<<last<<endl;
                    lastFreq += itr->second;
                } else {
                    if (lastFreq == 0)
                        res += 0;
                    else if (lastFreq == 1)
                        res++;
                    else if (lastFreq >= 100)
                        res += 4;
                    else if (lastFreq >= 10)
                        res += 3;
                    else if (lastFreq > 1)
                        res += 2;
                    last = itr->first;
                    lastFreq = itr->second;
                }
            }
            // cout<<last<<" "<<lastFreq<<endl;
            if (lastFreq == 0)
                res += 0;
            else if (lastFreq == 1)
                res++;
            else if (lastFreq >= 100)
                res += 4;
            else if (lastFreq >= 10)
                res += 3;
            else if (lastFreq > 1)
                res += 2;
            // cout<<res<<endl;
            return res;
        }
        int res = INT_MAX;
        for (auto itr = encoded.begin(); itr != encoded.end(); itr++) {
            if (itr->second == 0) continue;
            itr->second -= 1;
            res = min(res, help(encoded, k - 1));
            itr->second += 1;
        }
        // cout<<res<<endl;
        return res;
    }
};