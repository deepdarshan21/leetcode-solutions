#include <bits/stdc++.h>
using namespace std;

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;  // {score, age}
        int n = scores.size();
        for (int i = 0; i < n; i++) players.push_back({scores[i], ages[i]});
        // sort in decreasing order of score
        sort(players.begin(), players.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        int sum = 0, tmp, res = 0;
        sum += players[0].first;
        res = sum;
        tmp = players[0].second;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (players[i].second <= tmp || (flag == false && players[i].first == players[i - 1].first)) {
                sum += players[i].first;
                tmp = min(tmp, players[i].second);
                res = max(res, sum);
                if (players[i].first != players[i - 1].first) flag = true;
            } else {
                sum = players[i].first;
                tmp = players[i].second;
                res = max(res, sum);
                flag = false;
            }
        }
        return res;
    }
};