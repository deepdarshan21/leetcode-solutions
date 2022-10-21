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
   Approach: Tree Relink

   Edge Cases:

   Time Complexity: O(n) Space: O(log(n))
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 7.5 MB less than: 95.89%
   Remarks:
*/

class Solution {
   public:
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *res = new TreeNode();
        if (root == nullptr) return res->right;
        TreeNode *temp;
        temp = res;
        inorder(root, temp);
        return res->right;
    }
    TreeNode *inorder(TreeNode *root, TreeNode *temp) {
        if (root == nullptr) return temp;
        temp = inorder(root->left, temp);
        root->left = nullptr;
        temp->right = root;
        temp = root;
        return inorder(root->right, temp);
    }
};