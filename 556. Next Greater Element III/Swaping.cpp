#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Swaping and Sorting

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 36.55%
   Memory Usage: 6 MB less than: 26.90%
   Remarks:
*/

class Solution {
   public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size();
        int firstSwap = len - 1, secondSwap = len - 1;
        while (firstSwap > 0) {
            if (str[firstSwap] > str[firstSwap - 1]) {
                break;
            }
            firstSwap--;
        }
        if (firstSwap == 0) return -1;
        firstSwap--;
        while (firstSwap <= secondSwap) {
            if (str[firstSwap] < str[secondSwap]) {
                break;
            }
            secondSwap--;
        }
        swap(str[firstSwap], str[secondSwap]);
        sort(str.begin() + firstSwap + 1, str.end());
        if (stoll(str) >= pow(2, 31)) return -1;
        return stoi(str);
    }
};