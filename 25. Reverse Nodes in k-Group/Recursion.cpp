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


   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 23 ms faster than: 43.91%
   Memory Usage: 11.6 MB less than: 31.83%
*/

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            count++;
            temp = temp->next;
        }
        if (count != k) {
            return head;
        }
        ListNode *prev, *curr, *next;
        prev = nullptr;
        curr = head;
        next = curr->next;
        while (count--) {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr == nullptr) {
                break;
            }
            next = next->next;
        }
        head->next = reverseKGroup(temp, k);
        head = prev;
        return head;
    }
};