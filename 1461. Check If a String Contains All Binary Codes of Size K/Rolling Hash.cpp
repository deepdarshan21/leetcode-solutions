#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Rolling hash

   Edge Cases:

   Time Complexity: O(n) Space: O(2^k)
   Status:  Accepted
   Runtime: 1059 ms faster than: 59.24%
   Memory Usage: 92.8 MB less than: 73.68%
   Remarks:
*/

class Solution {
   public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        vector<int> sInt;
        for (char x : s) x == '0' ? sInt.push_back(0) : sInt.push_back(1);
        set<int> hashes;
        int hash = 0;
        for (int i = 0; i < k; i++) hash = hash * 2 + sInt[i];
        int power = pow(2, k - 1);
        hashes.insert(hash);
        for (int i = k; i < sInt.size(); i++) {
            hash = (hash - sInt[i - k] * power) * 2 + sInt[i];
            hashes.insert(hash);
        }
        if (hashes.size() == pow(2, k))
            return true;
        return false;
    }
};