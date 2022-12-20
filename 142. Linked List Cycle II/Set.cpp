#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
   Approach: Set
        Push each head into set and check if it is repeating or not

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 43 ms faster than: 5%
   Memory Usage: 9.8 MB less than: 11%
   Remarks:
*/

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return head;
        set<ListNode *> st;
        while (head != nullptr) {
            if (st.find(head) != st.end()) {
                return head;
            }
            st.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};