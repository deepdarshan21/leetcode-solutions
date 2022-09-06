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
   Approach: Use recursion to check that tree has 1 in it or not. And normal preorder traversal to check
        for each node

   Edge Cases:

   Time Complexity: O(n^2) Space: O(1)
   Status: Accepeted
   Runtime: 8 ms faster than: 15.99%
   Memory Usage: 8.9 MB less than: 21.13%
   Remarks:
*/

class Solution {
   public:
    TreeNode *pruneTree(TreeNode *root) {
        if (!subTreeHasOne(root)) {
            root = nullptr;
            return root;
        }
        if (subTreeHasOne(root->left)) {
            pruneTree(root->left);
        } else {
            root->left = nullptr;
        }
        if (subTreeHasOne(root->right)) {
            pruneTree(root->right);
        } else {
            root->right = nullptr;
        }
        return root;
    }

   private:
    bool subTreeHasOne(TreeNode *root) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == 1) {
            return 1;
        }
        if (subTreeHasOne(root->left) || subTreeHasOne(root->right)) {
            return true;
        }
        return false;
    }
};