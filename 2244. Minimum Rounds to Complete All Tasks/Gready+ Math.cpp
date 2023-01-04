#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 602 ms faster than: 22%
   Memory Usage: 103.6 MB less than: 89.36%
   Remarks:
*/

class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        int n = tasks.size();
        for (int i = 0; i < n; i++) mp[tasks[i]]++;
        int res = 0;
        for (auto itr : mp) {
            if (itr.second == 1) return -1;
            if (itr.second % 3 == 0)
                res += itr.second / 3;
            else
                res += itr.second / 3 + 1;
        }
        return res;
    }
};