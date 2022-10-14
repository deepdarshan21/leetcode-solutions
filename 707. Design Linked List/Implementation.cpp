#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Implementation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 112 ms faster than: 7.31%
   Memory Usage: 19.7 MB less than: 67.46%
   Remarks:
*/

class MyLinkedList {
   private:
    struct ListNode {
        int val;
        ListNode *next;
    };
    ListNode *head;

   public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        ListNode *temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            // cout<<temp->val<<" ";
            temp = temp->next;
        }
        // cout<<temp->val<< " "<<temp->val;
        // cout<<endl;
        if (temp == nullptr) return -1;
        return temp->val;
    }

    void addAtHead(int val) {
        ListNode *temp = new ListNode;
        temp->val = val;
        temp->next = head;
        head = temp;
        // temp = head;
        // while(temp!=nullptr){
        //     cout<<temp->val;
        //     temp = temp->next;
        // }
        // cout<<endl;
    }

    void addAtTail(int val) {
        ListNode *temp = head;
        if (head == nullptr) {
            head = new ListNode;
            head->val = val;
            head->next = nullptr;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode;
        temp = temp->next;
        temp->val = val;
        temp->next = nullptr;
    }

    void addAtIndex(int index, int val) {
        ListNode *temp = head;
        if (index == 0) {
            ListNode *temp1 = new ListNode;
            temp1->val = val;
            temp1->next = head;
            head = temp1;
            return;
        }
        for (int i = 0; i < index - 1 && temp != nullptr; i++) {
            // cout<<temp->val<<" ";
            temp = temp->next;
        }
        if (temp == nullptr) return;
        // cout<<endl;
        // cout<<temp->next->val<<endl;
        ListNode *temp1;
        temp1 = new ListNode;
        temp1->val = val;
        temp1->next = temp->next;
        temp->next = temp1;
        // cout<<head->val<<" "<<head->next->val<<" "<<head->next->next->val<<endl;
    }

    void deleteAtIndex(int index) {
        ListNode *temp = head;
        if (index == 0) {
            head = temp->next;
            return;
        }
        for (int i = 0; i < (index - 1) && temp->next != nullptr; i++) {
            // cout<<temp->val<<" ";
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        // cout<<"delete"<<endl;
        // cout<<temp->val<<endl;
        // cout<<endl;
        if (temp->next == nullptr) {
            head = nullptr;
            return;
        }
        temp->next = temp->next->next;
    }
};
