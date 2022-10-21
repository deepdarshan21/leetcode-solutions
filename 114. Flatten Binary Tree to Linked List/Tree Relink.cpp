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
   Approach: Without using extra space

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 23 ms faster than: 6.01%
   Memory Usage: 12.8 MB less than: 37.48%
   Remarks:
*/

class Solution {
   public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        TreeNode *temp = root;
        TreeNode *right, *nextRight;
        while (temp != nullptr) {
            if (temp->left != nullptr) {
                right = rightMost(temp->left);
                nextRight = temp->right;
                temp->right = temp->left;
                temp->left = nullptr;
                right->right = nextRight;
            }
            temp = temp->right;
        }
    }
    TreeNode *rightMost(TreeNode *root) {
        if (root->right == nullptr) return root;
        return rightMost(root->right);
    }
};