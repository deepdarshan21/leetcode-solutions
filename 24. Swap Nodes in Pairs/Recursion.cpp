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
        Swap the node's val between adjacent nodes of given linked list

   Edge Cases:


   Time Complexity: O(n) Space: O(n)
   Status:
   Runtime: 3 ms faster than: 70.40%
   Memory Usage: 7.7 MB less than: 7.45%
*/

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head != nullptr && head->next != nullptr) {
            int temp;
            temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
            swapPairs(head->next->next);
        }
        return head;
    }
};