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
   Approach: Recursion
        Use recursion for puting first element at first position

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 11 ms faster than: 52.08%
   Memory Usage: 11.6 MB less than: 99.41%
   Remarks:
*/

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* start = head;
        ListNode* temp;
        temp = head;
        int size = 0;
        while (temp->next->next != nullptr) {
            size++;
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = nullptr;
        return rotateRight(head, (k - 1) % (size + 1));
    }
};