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
        Take two lists at time and merge them in sorted order

   Edge Cases:
        1. If size of 'lists' vector is 0 -> return nullptr
        2. If size of 'lists' vector is 1 -> return list[0]
        3. While merging two lists if size of any of the list is 0

   Time Complexity: O(n*m) Space: O(n*m)
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
*/

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        ListNode* mergedList = nullptr;
        for (int i = 1; i < lists.size(); i++) {
            if (i == 1) {
                mergedList = mergeTwoLists(lists[0], lists[i]);
            } else {
                mergedList = mergeTwoLists(mergedList, lists[i]);
            }
        }
        return mergedList;
    }

   private:
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