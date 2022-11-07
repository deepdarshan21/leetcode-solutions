#include <bits/stdc++.h>
using namespace std;

/*
   Approach: I will require (maxFreq-1)+(n+1) and number of times maxFreq is the freq of other elements

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 71 ms faster than: 95.23%
   Memory Usage: 34.3 MB less than: 91.72%
   Remarks:
*/

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for (int task : tasks) {
            mp[task]++;
            maxFreq = max(maxFreq, mp[task]);
        }
        int res = (maxFreq - 1) * (n + 1);
        for (auto itr : mp)
            if (itr.second == maxFreq) res++;
        return res;
    }
};