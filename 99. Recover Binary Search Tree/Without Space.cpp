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
   Approach: Without extra space(Morris Traversal)

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 35 ms faster than: 78.58%
   Memory Usage: 57.7 MB less than: 92.98%
   Remarks:
*/

class Solution {
   public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        auto inorder = [&](auto inorder, TreeNode *root) {
            if (root == nullptr) return;
            inorder(inorder, root->left);
            if (prev != nullptr and prev->val > root->val) {
                if (first == nullptr) first = prev;
                second = root;
            }
            prev = root;
            inorder(inorder, root->right);
        };
        inorder(inorder, root);
        swap(first->val, second->val);
    }
};