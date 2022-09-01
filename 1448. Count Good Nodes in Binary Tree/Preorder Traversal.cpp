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
   Approach: Normal Tree Traversal
        Normally traverse the tree and record the highest element in the path of root to that node

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int goodNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int max = root->val;
        return 1 + help(root->left, max) + help(root->right, max);
    }

   private:
    int help(TreeNode *root, int maxTillNow) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val >= maxTillNow) {
            maxTillNow = root->val;
            return 1 + help(root->left, maxTillNow) + help(root->right, maxTillNow);
        }
        return 0 + help(root->left, maxTillNow) + help(root->right, maxTillNow);
    }
};