#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Simply store all the possible string in queue and set


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.7 MB less than: 15.87%
   Remarks:
*/

class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> que;
        set<string> seen;
        que.push(start);
        seen.insert(start);
        int steps = 0;
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                string node = que.front();
                que.pop();
                if (node == end) return steps;
                for (char c : "ACGT") {
                    for (int i = 0; i < node.size(); i++) {
                        string temp = node;
                        temp[i] = c;
                        if (!seen.count(temp) && find(bank.begin(), bank.end(), temp) != bank.end()) {
                            seen.insert(temp);
                            que.push(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};