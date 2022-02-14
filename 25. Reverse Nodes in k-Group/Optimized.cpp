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
   Approach:
        Reverse linked list in group of 'k' and add them again into the same linkedlist

   Edge Cases:


   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 23 ms faster than: 43.91%
   Memory Usage: 11.4 MB less than: 72.79%
*/

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *temp = head, *tempHead, *prevTemp, *nextPrevTemp;
        prevTemp = head;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }
        if (count == k) {
            head = reverseLinkedList(head, k, temp);
            count = 0;
            tempHead = temp;
            nextPrevTemp = tempHead;
        }
        while (temp != nullptr) {
            temp = temp->next;
            count++;
            if (count == k) {
                prevTemp->next = reverseLinkedList(tempHead, k, temp);
                count = 0;
                tempHead = temp;
                prevTemp = nextPrevTemp;
                nextPrevTemp = tempHead;
            }
        }
        return head;
    }

   private:
    ListNode* reverseLinkedList(ListNode* head, int k, ListNode* nextHead) {
        int count = 0;
        ListNode *curr = head, *prev = nextHead, *next;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head = prev;
        return head;
    }
};