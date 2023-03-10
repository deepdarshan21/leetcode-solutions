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
   Approach: Simply copy all the elements of linked list into array and then
    return a random element from the array.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 24 ms faster than: 63.90%
   Memory Usage: 16.7 MB less than: 57.94%
   Remarks:
*/

class Solution {
   private:
    vector<int> nums;

   public:
    Solution(ListNode *head) {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        int n = nums.size();
        int idx = rand() % n;
        return nums[idx];
    }
};