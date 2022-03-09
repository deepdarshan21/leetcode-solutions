#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sort


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 15 ms faster than: 49.72%
   Memory Usage: 10.7 MB less than: 37.96%
   Remarks:
*/

class Solution {
   public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> store;
        for (auto n : arr) {
            store.push_back({noOfOnes(n), n});
        }
        sort(store.begin(), store.end());
        vector<int> res;
        for (auto it : store) {
            res.push_back(it.second);
        }
        return res;
    }

   private:
    int noOfOnes(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};