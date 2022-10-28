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
   Approach: Basic BST creation

   Edge Cases:

   Time Complexity: O(n*logn) Space: O(n)
   Status: Accepted
   Runtime: 14 ms faster than: 22.83%
   Memory Usage: 12.6 MB less than: 97.44%
   Remarks:
*/

class Solution {
   public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        TreeNode *root = nullptr;
        int n = preorder.size();
        int i = 0;
        if (i < n) root = new TreeNode(preorder[i++]);
        while (i < n) {
            TreeNode *help = root;
            while (help != nullptr) {
                if (help->val > preorder[i]) {
                    if (help->left == nullptr) {
                        help->left = new TreeNode(preorder[i]);
                        break;
                    } else
                        help = help->left;
                } else {
                    if (help->right == nullptr) {
                        help->right = new TreeNode(preorder[i]);
                        break;
                    } else
                        help = help->right;
                }
            }
            i++;
        }
        return root;
    }
};