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
        Use a seperate data structure to store the elements of Linked List and then sort them and
        at last store them again in Linked List and return its head

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 146 ms faster than: 47.51%
   Memory Usage: 33.7 MB less than: 45.51%
   Remarks:
*/

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        vector<int> store;
        while (head != nullptr) {
            store.push_back(head->val);
            head = head->next;
        }
        sort(store.begin(), store.end());
        ListNode *sortedHead = new ListNode(0), *temp = sortedHead;
        for (auto element : store) {
            temp->next = new ListNode(element);
            temp = temp->next;
        }
        return sortedHead->next;
    }
};