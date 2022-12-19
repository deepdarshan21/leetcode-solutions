#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
   Approach: Maintain a prev pointer to compare if curr element matchs with prev then there is duplicate
        and now we need to remove that; For removing we update next pointer or prev with next next of curr
        it will skip the curr element from Linkedlist;


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 18 ms faster than: 63%
   Memory Usage: 18 MB less than: 38.67%
   Remarks:
*/

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *temp = head, *prev = nullptr;
        while (temp != nullptr) {
            if (prev != nullptr && prev->val == temp->val) {
                prev->next = temp->next;
            } else {
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};