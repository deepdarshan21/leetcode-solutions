#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 1457 ms faster than: 7.69%
   Memory Usage: 83.2 MB less than: 46.15%
   Remarks:
*/

class Solution {
   public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> numsCost(n);
        vector<long long> costs(n);
        // costs[0] = cost[0];
        for (int i = 0; i < n; i++) {
            numsCost[i] = {nums[i], cost[i]};
            // if(i>0) costs[i]+=costs[i-1];
            // cout<<costs[i]<<" ";
        }
        sort(numsCost.begin(), numsCost.end());
        costs[0] = numsCost[0].second;
        // cout<<costs[0]<<" ";
        for (int i = 1; i < n; i++) {
            costs[i] = numsCost[i].second + costs[i - 1];
            // cout<<costs[i]<<" ";
        }
        // cout<<endl;

        long long temp = 0, res;
        for (int i = 0; i < n; i++) {
            temp += (numsCost[i].first - numsCost[0].first) * (long long)numsCost[i].second;
        }
        // cout<<temp<<endl;
        res = temp;
        // long long temp;
        int j = 1;
        int start = numsCost[0].first, end = numsCost[n - 1].first;
        // cout<<start<<" "<<end<<endl;
        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            count++;
            temp = temp + costs[j - 1] - (costs[n - 1] - costs[j - 1]);
            // cout<<i<<" "<<temp<<endl;
            if (i == numsCost[j].first) {
                // cout<<"here"<<endl;
                res = min(res, temp);
                j++;
                while (j < (n) && numsCost[j].first == numsCost[j - 1].first) j++;
                // cout<<"Check "<<res<<" "<<j<<endl;
            }
        }
        // cout<<n<<" "<<j<<endl;
        // cout<<numsCost[267].first<<endl;
        // cout<<count<<endl;
        return res;
    }
};