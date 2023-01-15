#include <bits/stdc++.h>
using namespace std;

/*
   Approach: DSU
        Group all O that has path from corner

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 36 ms faster than: 22.42%
   Memory Usage: 10.3 MB less than: 53.45%
   Remarks:
*/

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> par(m * n);

        auto findPar = [&](auto findPar, int node) {
            if (par[node] == node) return node;
            return par[node] = findPar(findPar, par[node]);
        };
        auto uniteN1AndN2 = [&](int n1, int n2) {
            int parN1 = findPar(findPar, n1);
            int parN2 = findPar(findPar, n2);
            if (parN1 != parN2) par[parN1] = parN2;
        };
        auto isConnected = [&](int n1, int n2) {
            return findPar(findPar, n1) == findPar(findPar, n2);
        };

        for (int i = 0; i < (m * n); i++) par[i] = i;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == (m - 1) || j == (n - 1)) {
                        uniteN1AndN2(i * n + j, m * n);
                    } else {
                        if (i > 0 && board[i - 1][j] == 'O') uniteN1AndN2(i * n + j, (i - 1) * n + j);
                        if (i < (m - 1) && board[i + 1][j] == 'O') uniteN1AndN2(i * n + j, (i + 1) * n + j);
                        if (j > 0 && board[i][j - 1] == 'O') uniteN1AndN2(i * n + j, i * n + (j - 1));
                        if (j < (n - 1) && board[i][j + 1] == 'O') uniteN1AndN2(i * n + j, i * n + (j + 1));
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && isConnected(i * n + j, m * n)) board[i][j] = 'X';
            }
        }
    }
};