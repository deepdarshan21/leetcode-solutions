#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Greedy(Priority Queue)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 95 ms faster than: 84.87%
   Memory Usage: 19.9 MB less than: 99.83%
   Remarks:
*/

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(hand.begin(), hand.end());
        for (int num : hand) {
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
                    if (temp.second < groupSize) return false;
                }
            }
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            while (!pq.empty() && pq.top().second == groupSize) pq.pop();
        }
        // cout<<pq.size()<<endl;
        // cout<<pq.top().first<<" "<<pq.top().second<<endl;
        return pq.size() == 0;
    }
};