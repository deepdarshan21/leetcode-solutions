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
       Just swap the adjacent nodes completely

   Edge Cases:


   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 57.49%
   Memory Usage: 7.6 MB less than: 55.55%
*/

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head != nullptr && head->next != nullptr) {
            ListNode *nextCall, *tempHead;
            nextCall = head->next->next;
            tempHead = head;
            head = head->next;
            head->next = tempHead;
            head->next->next = swapPairs(nextCall);
        }
        return head;
    }
};