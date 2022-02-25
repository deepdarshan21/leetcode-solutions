#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
   Approach: Merge Sort


   Edge Cases:

   Time Complexity: O(nlogn) Space: O(logn)
   Status: Accepted
   Runtime: 144 ms faster than: 48.83%
   Memory Usage: 29.1 MB less than: 87.85%
   Remarks:
*/

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *temp, *slow, *fast;
        slow = fast = head;
        temp = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        ListNode *l1, *l2;
        l1 = sortList(head);
        l2 = sortList(slow);

        return mergeSort(l1, l2);
    }

   private:
    ListNode* mergeSort(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *head, *temp;
        if (l2->val < l1->val) {
            head = l2;
            while (l2 != nullptr && l2->val < l1->val) {
                temp = l2;
                l2 = l2->next;
            }
        } else {
            head = l1;
            temp = l1;
            l1 = l1->next;
        }
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1 == nullptr) {
            temp->next = l2;
        }
        if (l2 == nullptr) {
            temp->next = l1;
        }
        return head;
    }
};