#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit Manipulation
        First create the vacency for next binary number by bitwise LEFT SHIFT and then add that
        element at end by bitwise OR.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 8.2 MB less than: 93.88%
   Remarks:
*/

class Solution {
   public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head != nullptr) {
            res = res << 1 | head->val;
            head = head->next;
        }
        return res;
    }
};