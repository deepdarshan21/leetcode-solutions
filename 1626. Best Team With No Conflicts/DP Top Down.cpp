#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DP(top down)
        First sort the players by age and then by score.
        Then for each player, we can either choose to include him or not.(2^N-1 choices)

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n^2)
   Status: Accepted
   Runtime: 956 ms faster than: 5.51%
   Memory Usage: 133.9 MB less than: 13.64%
   Remarks:
*/

class Solution {
   public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players;  // {age, score}
        for (int i = 0; i < n; i++) players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));  // {index, last player index}
        auto help = [&](auto help, int prev, int i) -> int {
            if (i == n) return 0;
            if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
            int ans = 0;
            if (prev == -1 || players[i].second >= players[prev].second) {
                ans = max(ans, players[i].second + help(help, i, i + 1));
            }
            ans = max(ans, help(help, prev, i + 1));
            return dp[i][prev + 1] = ans;
        };
        return help(help, -1, 0);
    }
};