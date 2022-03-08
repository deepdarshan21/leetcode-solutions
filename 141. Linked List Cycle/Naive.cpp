#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Wrong answer
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        vector<ListNode *> store;
        store.push_back(head);
        while (head->next != nullptr) {
            if (find(store.begin(), store.end(), head->next) == store.end()) {
                return false;
            }
        }
        return true;
    }
};