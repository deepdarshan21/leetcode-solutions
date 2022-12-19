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
   Approach: Same as reverse linkedlist but in some constraints

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 7 ms faster than: 23%
   Memory Usage: 7.5 MB less than: 18%
   Remarks:
*/

class Solution {
   public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head == nullptr) return head;
        int count = 0;
        ListNode *temp = head, *p = nullptr;
        while (temp != nullptr) {
            if (count == (left - 1)) {
                // reverse linked list
                ListNode *prev = nullptr, *curr = temp, *next;
                while (count < right && curr != nullptr) {
                    // main logic
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    count++;
                }
                temp->next = curr;
                if (p != nullptr)
                    p->next = prev;
                else
                    head = prev;
                break;
            }
            count++;
            p = temp;
            temp = temp->next;
        }
        return head;
    }
};