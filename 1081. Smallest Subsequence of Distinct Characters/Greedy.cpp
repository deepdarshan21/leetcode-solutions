#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        First store the last index of every index using map
        Then, use a stack for storing result in reverse order and a map for checking that an element is
        in answer or not
            if element is already in answer stack than leave it
            else
                remove the elements from answer stack if top element of stack is after there till top element
                become smaller than top element of stack
            add new element on top of answer stack

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 6 ms faster than: 22551.%
   Memory Usage: 6.5 MB less than: 34.34%
   Remarks:
*/

class Solution {
   public:
    string removeDuplicateLetters(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }
        string res = "";
        map<char, bool> isVisited;
        for (int i = 0; i < s.size(); i++) {
            if (isVisited[s[i]] == true) {
                continue;
            }
            while (!res.empty() && res.back() > s[i] && mp[res.back()] > i) {
                isVisited[res.back()] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            isVisited[s[i]] = true;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};