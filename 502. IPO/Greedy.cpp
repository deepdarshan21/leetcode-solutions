#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy
        Use a priority queue to store the max profit projects.
        Sort the projects by capital.
        Loop k times:
            Add all projects that can be done with current capital.
            If there is no project that can be done, break.
            Add the max profit project to current profit.

   Edge Cases:

   Time Complexity: O(klogk) Space: O(n)
   Status: Accepted
   Runtime: 236 ms faster than: 61.32%
   Memory Usage: 82.1 MB less than: 53.52%
   Remarks:
*/

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // priority queue for max profit
        priority_queue<int> maxProfit;
        int currentCapital = w;
        int currentProfit = 0;
        int currentProject = 0;
        int n = profits.size();
        // sort the projects by capital
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        // loop k times
        for (int i = 0; i < k; i++) {
            // add all projects that can be done with current capital
            while (currentProject < n && projects[currentProject].first <= currentCapital) {
                maxProfit.push(projects[currentProject].second);
                currentProject++;
            }
            // if there is no project that can be done, break
            if (maxProfit.empty()) {
                break;
            }
            // add the max profit project to current profit
            currentCapital += maxProfit.top();
            maxProfit.pop();
        }
        return currentCapital;
    }
};