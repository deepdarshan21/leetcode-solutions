#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Implemantation of Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.3 MB less than: 36.35%
   Remarks:
*/

class Solution {
   public:
    bool checkValidString(string s) {
        vector<pair<char, int>> st;
        int lastA = -1, lastB = -1;
        // bool res = false;
        for (int i = 0; i < s.size(); i++) {
            // cout<<i<<" "<<s[i]<<" ";
            if (s[i] == '(') {
                st.push_back({s[i], lastB});
                lastB = i;
            } else if (s[i] == '*') {
                st.push_back({s[i], lastA});
                lastA = i;
            } else if (s[i] == ')') {
                st.push_back({s[i], -1});
                // cout<<endl;
                // cout<<"Check "<<lastA<<" "<<lastB<<endl;
                if (lastB != -1) {
                    // cout<<"Check1 "<<st[lastB].first<<" "<<st[lastB].second<<endl;
                    int temp = st[lastB].second;
                    // cout<<temp<<endl;
                    // st.erase(st.begin() + lastB);
                    lastB = temp;
                } else if (lastA != -1) {
                    int temp = st[lastA].second;
                    lastA = temp;
                } else {
                    return false;
                }
                // cout<<"Check "<<lastA<<" "<<lastB<<endl;
            }
            // cout<<st.back().first<<" "<<st.back().second<<endl;
        }
        // cout<<"Check "<<lastA<<" "<<lastB<<endl;
        if (lastB == -1) return true;
        while (lastA != -1 && lastB != -1 && lastA > lastB) {
            // if (lastB == -1) return false;
            lastA = st[lastA].second;
            lastB = st[lastB].second;
            // cout<<lastA<<" "<<lastB<<endl;
        }
        return lastB == -1;
    }
};