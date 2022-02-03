#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Basic Math
       

   Edge Cases:
       

   Time Complexity: O(n) Space: O(1)
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0, ListNode* suml = nullptr) {
        int sum;
        if (l1 == nullptr && l2 == nullptr && carry != 0) {
            sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            if (suml == nullptr) {
                suml = new ListNode;
                suml->val = sum;
            } else {
                ListNode* temp;
                // temp = suml;
                // while (temp->next != nullptr) {
                //     temp = temp->next;
                // }
                // temp->next = new ListNode;
                // temp = temp->next;
                // temp->val = sum;
                temp = new ListNode;
                temp->val = sum;
                suml->next = temp;
                suml = suml->next;
            }
            addTwoNumbers(l1, l2, carry, suml);
        }
        if (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                sum = l1->val + l2->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                // l1->val = sum;
                // if (l1->next != nullptr)
                l1 = l1->next;
                // else
                //     l1 = new ListNode;
                l2 = l2->next;
            } else if (l1 == nullptr && l2 != nullptr) {
                sum = l2->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                l2 = l2->next;
            } else if (l1 != nullptr && l2 == nullptr) {
                sum = l1->val + carry;
                carry = sum / 10;
                sum = sum % 10;
                l1 = l1->next;
            }
            if (suml == nullptr) {
                suml = new ListNode;
                suml->val = sum;
            } else {
                ListNode* temp;
                // temp = suml;
                // while (temp->next != nullptr) {
                //     temp = temp->next;
                // }
                // temp->next = new ListNode;
                // temp = temp->next;
                // temp->val = sum;
                temp = new ListNode;
                temp->val = sum;
                suml->next = temp;
                suml = suml->next;
            }
            addTwoNumbers(l1, l2, carry, suml);
        }
        // addTwoNumbers();
        return suml;
    }
};