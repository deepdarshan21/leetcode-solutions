#include <bits/stdc++.h>
using namespace std;

/*
   Approach:Greedy + Sorting
        Once you fix the position of the shortest person,
        what can you say about the position of the second shortest person?

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accepted
   Runtime: 88 ms faster than: 84.40%
   Memory Usage: 12.2 MB less than: 47.84%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> res(n, {-1, -1});
        sort(people.begin(), people.end());
        for (int i = 0; i < n; i++) {
            vector<int> temp = people[i];
            // cout<<temp[0]<<" "<<temp[1]<<endl;
            int count = 0, j = 0;
            while (count < temp[1] && j < n) {
                if (res[j][0] == -1 || temp[0] <= res[j][0]) count++;
                j++;
            }
            // cout<<endl;
            while (j < n) {
                if (res[j][0] == -1) break;
                j++;
            }
            res[j] = temp;
            // cout<<j<<endl;
        }
        return res;
    }
};