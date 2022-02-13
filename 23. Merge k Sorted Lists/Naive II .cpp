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
        First add all element(val) of lists' list in to array and then sort the array and
        finally create new Linked List with help of sorted array

   Edge Cases:
        1. No element in array

   Time Complexity: O((m+n)log(m+n)) Space: O(m+n)
   Status: Accepted
   Runtime: 30 ms faster than: 66.02%
   Memory Usage: 14 MB less than: 25.65%
*/

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> storeAllVal;
        ListNode* temp;
        for (int i = 0; i < lists.size(); i++) {
            temp = lists[i];
            while (temp != nullptr) {
                storeAllVal.push_back(temp->val);
                temp = temp->next;
            }
        }
        if (storeAllVal.size() == 0) {
            return nullptr;
        }

        sort(storeAllVal.begin(), storeAllVal.end());

        ListNode* mergedList = new ListNode(storeAllVal[0]);
        temp = mergedList;
        for (int i = 1; i < storeAllVal.size(); i++) {
            temp->next = new ListNode(storeAllVal[i]);
            temp = temp->next;
        }

        return mergedList;
    }
};