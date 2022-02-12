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
   Approach: Brute Force(Single Pass)
        Assume first element as the nth element from end, and then move it towards the end
        accoedingly to size of linked list

   Edge Cases:
        1. If target element is the first element

   Time Complexity: O(n) Space: O(1)
   Status: Accepeted
   Runtime: 4 ms faster than: 80.44%
   Memory Usage: 10.6 MB less than: 96.70%
*/

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0 || head == nullptr) {
            return head;
        }
        ListNode *temp, *tempNthNode;
        temp = head;
        tempNthNode = head;
        while (temp != nullptr) {
            if (n == -1) {
                tempNthNode = tempNthNode->next;
            } else {
                n--;
            }
            temp = temp->next;
        }
        if (n == 0) {
            return head->next;
        }
        tempNthNode->next = tempNthNode->next->next;
        return head;
    }
};