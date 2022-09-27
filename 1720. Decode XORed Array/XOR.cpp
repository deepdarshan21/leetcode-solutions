#include <bits/stdc++.h>
using namespace std;

/*
   Approach: XOR

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 65 ms faster than: 31.57%
   Memory Usage: 26 MB less than: 55.90%
   Remarks:
*/

class Solution {
   public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        int n = encoded.size();
        for (int i = 0; i < n; i++) {
            res.push_back(encoded[i] ^ res[i]);
        }
        return res;
    }
};