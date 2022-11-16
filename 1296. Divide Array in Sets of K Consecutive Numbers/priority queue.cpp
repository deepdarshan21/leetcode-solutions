#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priority Queue

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 199 ms faster than: 93.07%
   Memory Usage: 36.5 MB less than: 99.41%
   Remarks:
*/

class Solution {
   public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            // cout<<num<<endl;
            if (pq.empty())
                pq.push({num, 1});
            else {
                pair<int, int> temp = pq.top();
                if (temp.first == num) {
                    pq.push({num, 1});
                } else if (num == (temp.first + 1)) {
                    // cout<<"here"<<endl;
                    // cout<<" "<<num<<" "<<temp.second+1<<endl;
                    pq.pop();
                    pq.push({num, temp.second + 1});
                } else {
                    if (temp.second < k) return false;
                }
            }
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            while (!pq.empty() && pq.top().second == k) pq.pop();
        }
        // cout<<pq.size()<<endl;
        // cout<<pq.top().first<<" "<<pq.top().second<<endl;
        return pq.size() == 0;
    }
};