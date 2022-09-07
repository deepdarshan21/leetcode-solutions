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
   Approach: Normal preorder traversal with modification in recursion


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 58 ms faster than: 21.51%
   Memory Usage: 53.7 MB less than: 36.36%
   Remarks:
*/

class Solution {
   public:
    string tree2str(TreeNode *root) {
        string res = "";
        if (root == nullptr) {
            return res;
        }
        res += to_string(root->val);
        if (root->left != nullptr) {
            res += "(";
            res += tree2str(root->left);
            res += ")";
            if (root->right != nullptr) {
                res += "(";
                res += tree2str(root->right);
                res += ")";
            }
        } else {
            if (root->right != nullptr) {
                res += "()(";
                res += tree2str(root->right);
                res += ")";
            }
        }
        return res;
    }
};