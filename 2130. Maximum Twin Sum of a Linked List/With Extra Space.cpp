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
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int pairSum(ListNode *head) {
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        int res = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            res = max(res, nums[i] + nums[nums.size() - 1 - i]);
        }
        return res;
    }
};