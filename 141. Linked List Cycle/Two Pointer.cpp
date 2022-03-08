#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
   Approach: Floyd’s Cycle-Finding Algorithm(two pointer)


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 8 ms faster than: 95.50%
   Memory Usage: 8.1 MB less than: 17.34%
   Remarks:
*/

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        fast = slow = head;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << fast->val << " " << slow->val << endl;
                return true;
            }
        }
        return false;
    }
};