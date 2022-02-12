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
        First count the number of nodes in the linked list and then accordingly find the
        position o target element form start using size of linked list and positon from end.

   Edge Cases:
        1. n==0 -> just return the original list
        2. if target element is at very start of list

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 88.02%
   Memory Usage: 10.7 MB less than: 75.13%
*/

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) {
            return head;
        }
        int size = 0;
        ListNode* temp;
        temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        int target = size - n + 1, start = 0;
        if (target == 1) {
            return head->next;
        }

        temp = head;
        while (temp != nullptr) {
            start++;
            if (start == target - 1) {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};