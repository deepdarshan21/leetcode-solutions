#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using stack concept

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 13 ms faster than: 26.08%
   Memory Usage: 6.8 MB less than: 84.21%
   Remarks:
*/

class Solution {
   public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int count = 1;
        while (getline(ss, curr, ',')) {
            count--;
            if (count < 0) return false;
            if (curr != "#") count += 2;
        }
        return count == 0;
    }
};