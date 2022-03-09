#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
   Approach: Maths
        Multiply the previous result by 2 and add current number.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 44.51%
   Memory Usage: 8.3 MB less than: 19.65%
   Remarks:
*/

class Solution {
   public:
    int getDecimalValue(ListNode *head) {
        int res = 0;
        while (head != nullptr) {
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};