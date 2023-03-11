#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
   Approach: Using extra space

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 24 ms faster than: 84.58%
   Memory Usage: 28.7 MB less than: 15.67%
   Remarks:
*/

class Solution {
   public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        auto rec = [&](auto self, int l, int r) -> TreeNode * {
            if (l > r) return nullptr;
            int mid = l + (r - l) / 2;
            TreeNode *root = new TreeNode(arr[mid]);
            root->left = self(self, l, mid - 1);
            root->right = self(self, mid + 1, r);
            return root;
        };
        return rec(rec, 0, arr.size() - 1);
    }
};