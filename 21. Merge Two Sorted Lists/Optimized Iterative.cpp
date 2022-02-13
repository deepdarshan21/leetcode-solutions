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
        Add link to element according to sorted order.

   Edge Cases:
        1. If size of any of the list is 0

   Time Complexity: O(m+n) Space: O(1)
   Status: Accepted
   Runtime: 4 ms faster than: 80.75%
   Memory Usage: 14.8 MB less than: 82.54%
*/

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* mergedList = nullptr;
        if (list1->val < list2->val) {
            mergedList = list1;
            list1 = list1->next;
        } else {
            mergedList = list2;
            list2 = list2->next;
        }
        ListNode* temp;
        temp = mergedList;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }

        if (list1 == nullptr) {
            temp->next = list2;
        }
        if (list2 == nullptr) {
            temp->next = list1;
        }
        return mergedList;
    }
};