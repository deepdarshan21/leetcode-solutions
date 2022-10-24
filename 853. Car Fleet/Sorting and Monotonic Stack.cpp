#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting and monotonic stack
        First make a vector pair and sort them
        Then move from right(as rightmost will be closest to target and it will take long time as compare to
        its left neighbor, if there is car fleet)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 413 ms faster than: 55.94%
   Memory Usage: 78.7 MB less than: 63.55%
   Remarks:
*/

class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        int n = position.size();
        for (int i = 0; i < n; i++) arr.push_back({position[i], speed[i]});
        sort(arr.begin(), arr.end());
        stack<double> st;
        for (int i = n - 1; i >= 0; i--) {
            double temp = (target - arr[i].first) / (double)arr[i].second;
            if (st.empty() || (!st.empty() && st.top() < temp)) st.push(temp);
        }
        return st.size();
    }
};