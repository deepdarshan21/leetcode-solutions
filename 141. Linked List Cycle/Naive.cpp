#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
   Approach: Storing the address of each node


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 255 ms faster than: 5.27%
   Memory Usage: 8.9 MB less than: 16.03%
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