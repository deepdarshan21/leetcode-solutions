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
   Approach: To LEFT SHIFT to one root->val times and XOR to store only odd freq digits. And at last when
   we are at leaf node check that there should be at max only one digit with freq to be odd.


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 515 ms faster than: 69.63%
   Memory Usage: 179.4 MB less than: 88.01%
   Remarks:
*/

class Solution {
   public:
    int pseudoPalindromicPaths(TreeNode *root) {
        int store = 0;
        return help(root, store);
    }

   private:
    int help(TreeNode *root, int store) {
        if (root == nullptr) {
            return 0;
        } else {
            store = store ^ (1 << root->val);
        }
        if (root->left != nullptr && root->right != nullptr) {
            return help(root->left, store) + help(root->right, store);
        } else if (root->left != nullptr && root->right == nullptr) {
            return help(root->left, store);
        } else if (root->left == nullptr && root->right != nullptr) {
            return help(root->right, store);
        } else {
            if ((store & (store - 1)) != 0) return 0;
            return 1;
        }
    }
};