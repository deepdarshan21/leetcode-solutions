#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
   Approach: Use extra space

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 39 ms faster than: 66.62%
   Memory Usage: 59.9 MB less than: 6.81%
   Remarks:
*/

class Solution {
   public:
    void recoverTree(TreeNode *root) {
        vector<int> inorder;
        // inorder traversal using stack
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while (curr != nullptr or !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        // find the two swapped elements
        int x, y;
        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i + 1] < inorder[i]) {
                x = inorder[i];
                break;
            }
        }
        for (int i = inorder.size() - 1; i > 0; i--) {
            if (inorder[i - 1] > inorder[i]) {
                y = inorder[i];
                break;
            }
        }
        auto swap = [&](TreeNode *root, auto swap) {
            if (root == nullptr) return;
            if (root->val == x or root->val == y) {
                root->val = root->val == x ? y : x;
            }
            swap(root->left, swap);
            swap(root->right, swap);
        };
        swap(root, swap);
    }
};