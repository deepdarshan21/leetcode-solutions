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
   Approach:


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status:Accepted
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int minDiffInBST(TreeNode *root) {
        int res = INT_MAX;
        TreeNode *pre = nullptr;
        auto inorder = [&](auto inorder, TreeNode *root) -> void {
            if (!root) return;
            inorder(inorder, root->left);
            if (pre) res = min(res, root->val - pre->val);
            pre = root;
            inorder(inorder, root->right);
        };
        inorder(inorder, root);
    }
};