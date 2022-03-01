#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Unordered Map
        Use unordered map for storing and accessing element in O(1).
        This will help to identify cycle, if any.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 42.97%
   Memory Usage: 6.2 MB less than: 51.52%
   Remarks:
*/

class Solution {
   public:
    bool isHappy(int n) {
        unordered_map<int, bool> store;
        int temp;
        do {
            temp = 0;
            store[n] = true;
            while (n != 0) {
                temp += pow(n % 10, 2);
                n /= 10;
            }
            n = temp;
            if (temp == 1) {
                return true;
            }
        } while (store[temp] != true);
        return false;
    }
};