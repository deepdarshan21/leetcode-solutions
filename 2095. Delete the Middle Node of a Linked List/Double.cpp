#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
   Approach: Fast slow approach linked list

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 2090 ms faster than: 42.28%
   Memory Usage: 294.8 MB less than: 20.46%
   Remarks:
*/

class Solution {
   public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *one, *two, *prev = nullptr;
        one = two = head;
        while (two != nullptr && two->next != nullptr) {
            two = two->next->next;
            prev = one;
            one = one->next;
        }
        if (prev == nullptr) return nullptr;
        prev->next = prev->next->next;
        return head;
    }
};