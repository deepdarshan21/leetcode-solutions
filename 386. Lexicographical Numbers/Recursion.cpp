#include <bits/stdc++.h>
using namespace std;

/*
   Approach: recursion

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 20 ms faster than: 53.10%
   Memory Usage: 11.4 MB less than: 61.81%
   Remarks:
*/

class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; i++) {
            helper(n, i, res);
        }
        return res;
    }

   private:
    void helper(int n, int num, vector<int>& res) {
        if (num > n) return;
        res.push_back(num);
        for (int i = 0; i < 10; i++) {
            helper(n, num * 10 + i, res);
        }
    }
};