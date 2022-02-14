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
   Approach: Brute Force
        Traverse two element at one time and then add that traversed element in swapped
        manner into a new Linked List

   Edge Cases:
        1. Size of given Linked List is 0

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 57.58%
   Memory Usage: 7.6 MB less than: 55.54%
*/

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *tempHead, *swapedList = new ListNode(), *tempSwaped;
        int temp1, temp2;
        tempHead = head;
        tempSwaped = swapedList;
        while (tempHead != nullptr && tempHead->next != nullptr) {
            temp1 = tempHead->val;
            temp2 = tempHead->next->val;
            tempSwaped->next = new ListNode(temp2);
            tempSwaped->next->next = new ListNode(temp1);
            tempSwaped = tempSwaped->next->next;
            tempHead = tempHead->next->next;
        }
        if (tempHead != nullptr) {
            tempSwaped->next = new ListNode(tempHead->val);
        }
        return swapedList->next;
    }
};