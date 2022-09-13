#include <bits/stdc++.h>
using namespace std;

/*
   Approach:First try to find the number of bytes and then satisfy the condition

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 35 ms faster than: 15.46%
   Memory Usage: 14.1 MB less than: 38.65%
   Remarks:
*/

class Solution {
   public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; i++) {
            int number_of_bytes = 0, val = data[i];
            if (val > 255)
                return false;
            else if ((val & 128) == 0)
                number_of_bytes = 1;
            else if ((val & 224) == 192)
                number_of_bytes = 2;
            else if ((val & 240) == 224)
                number_of_bytes = 3;
            else if ((val & 248) == 240)
                number_of_bytes = 4;
            else
                return false;

            for (int j = 1; j < number_of_bytes; j++) {
                if ((i + j) >= n) return false;
                val = data[i + j];
                if ((val & 192) != 128) return false;
            }
            i = i + number_of_bytes - 1;
        }
        return true;
    }
};