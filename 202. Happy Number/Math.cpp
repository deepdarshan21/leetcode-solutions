#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 5 ms faster than: 25.01%
   Memory Usage: 5.8 MB less than: 94.35%
   Remarks:
*/

class Solution {
   public:
    bool isHappy(int n) {
        int temp;
        while (true) {
            temp = 0;
            while (n != 0) {
                temp += pow(n % 10, 2);
                n /= 10;
            }
            if (temp / 10 == 0) {
                if (temp == 1 || temp == 7) {
                    return true;
                } else {
                    return false;
                }
            }
            n = temp;
        }
        return false;
    }
};