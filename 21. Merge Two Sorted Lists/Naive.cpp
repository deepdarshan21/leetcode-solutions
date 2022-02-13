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
        Create a seprate new linked list and elements to it, according to sorted order

   Edge Cases:
        1. If size of any of the linked list is 0

   Time Complexity: O(m+n) Space: O(m+n)
   Status: Accepted
   Runtime: 4 ms faster than: 9499%
   Memory Usage: 14.9 MB less than: 15.40%
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
        ListNode *mergedList = nullptr, *temp;
        if (list1->val < list2->val) {
            mergedList = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            mergedList = new ListNode(list2->val);
            list2 = list2->next;
        }
        temp = mergedList;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 == nullptr) {
            temp->next = list2;
        } else {
            temp->next = list1;
        }

        return mergedList;
    }
};