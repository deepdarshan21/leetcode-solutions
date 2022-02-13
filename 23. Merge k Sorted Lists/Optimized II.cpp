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
        Traverse all the list from "lists" and find the smallest(minimum) among them
        and then add that node's link to mergedList.

   Edge Cases:
        1. If size of 'lists' vector is 0 -> return nullptr

   Time Complexity: O(nm) Space: O(1)
   Status: Accepted
   Runtime: 1457 ms faster than: 5.00%
   Memory Usage: 13 MB less than: 95.99%
*/

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *mergedList = new ListNode(), *temp = mergedList;

        bool isAllNull = false;
        while (true) {
            int minVal = INT_MAX;
            ListNode* minValPos;
            for (int i = 0; i < lists.size(); i++) {
                if (i == 0 && lists[0] == nullptr) {
                    isAllNull = true;
                }
                if (isAllNull == true && lists[i] != nullptr) {
                    isAllNull = false;
                }
                if (lists[i] != nullptr) {
                    if (minVal > lists[i]->val) {
                        minVal = lists[i]->val;
                        minValPos = lists[i];
                    }
                }
            }
            if (isAllNull == true) {
                break;
            }
            temp->next = minValPos;
            temp = temp->next;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == minValPos) {
                    lists[i] = lists[i]->next;
                    break;
                }
            }
        }

        return mergedList->next;
    }
};