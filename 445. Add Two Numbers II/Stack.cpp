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
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 67 ms faster than: 52.09%
   Memory Usage: 73.8 MB less than: 20.10%
   Remarks:
*/

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1 != nullptr) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *root, *temp;
        root = nullptr;
        // temp = root;
        int carry = 0, sum;
        while (!st1.empty() || !st2.empty()) {
            sum = carry;
            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }
            carry = sum / 10;
            temp = root;
            root = new ListNode(sum % 10);
            root->next = temp;
        }
        if (carry != 0) {
            temp = root;
            root = new ListNode(carry);
            root->next = temp;
        }
        return root;
    }
};