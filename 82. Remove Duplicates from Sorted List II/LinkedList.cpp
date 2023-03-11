#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
   Approach: Recusion

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 14 ms faster than: 20.58%
   Memory Usage: 11.2 MB less than: 23.63%
   Remarks:
*/

class Solution {
   public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *curr = head->next, *prev = head;
        bool flag = false;
        while (curr->val == prev->val) {
            flag = true;
            curr = curr->next;
            if (!curr) return nullptr;
        }
        if (flag) return deleteDuplicates(curr);
        head->next = deleteDuplicates(curr);
        return head;
    }
};