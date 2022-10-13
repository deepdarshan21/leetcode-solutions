#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
   Approach: You can't delete the node directly but you can delete the next node of it, so for doing
    the same we will first copy the next node in it can then delete the next node;

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 13 ms faster than: 90.82%
   Memory Usage: 7.6 MB less than: 37.95%
   Remarks:
*/

class Solution {
   public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};