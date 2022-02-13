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
        Create a new Linked List and add elements from both list according to its sorted order

   Edge Cases:
        1. Size of either of Linked List is 0

   Time Complexity: O(m+n) Space: O(m+n)
   Status: Accepted
   Runtime: 14 ms faster than: 31.33%
   Memory Usage: 22.7 MB less than: 9.10%
*/

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2, ListNode* merged = nullptr) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        if (list1->val < list2->val) {
            merged = new ListNode(list1->val);
            merged->next = mergeTwoLists(list1->next, list2, merged->next);
        } else {
            merged = new ListNode(list2->val);
            merged->next = mergeTwoLists(list1, list2->next, merged->next);
        }
        return merged;
    }
};