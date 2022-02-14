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
        First store all the value of nodes into a vector and do "reverseKGroup opertation"
        on that and then create a new linked list and put that vector's value into it

   Edge Cases:


   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 30 ms faster than: 23.20%
   Memory Usage: 12.06 MB less than: 6.05%
*/

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> store;
        while (head != nullptr) {
            store.push_back(head->val);
            head = head->next;
        }
        // vector<int>::iterator it;
        // for (it = store.begin(); it + k != store.end(); it += k) {
        //     reverse(it, it + k);
        // }
        for (int i = 0; i + k <= store.size(); i += k) {
            reverse(store.begin() + i, store.begin() + i + k);
        }
        ListNode *reverseKGroup = new ListNode(), *temp = reverseKGroup;
        for (int i = 0; i < store.size(); i++) {
            temp->next = new ListNode(store[i]);
            temp = temp->next;
        }
        return reverseKGroup->next;
    }
};