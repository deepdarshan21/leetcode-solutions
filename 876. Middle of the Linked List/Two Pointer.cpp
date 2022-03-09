#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
   Approach: Two Pointer
        Check for middle in every iteration on  given liked list

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7.1 MB less than: 73.11%
   Remarks:
*/

class Solution {
   public:
    ListNode *middleNode(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        int size = 0;
        size++;
        ListNode *temp, *midStore;
        midStore = head;
        temp = head;
        while (temp->next != nullptr) {
            size++;
            if (size % 2 == 0) {
                midStore = midStore->next;
            }
            temp = temp->next;
        }
        return midStore;
    }
};