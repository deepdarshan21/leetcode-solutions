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
   Approach: Tree Construction

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 29 ms faster than: 66%
   Memory Usage: 27 MB less than: 16.44%
   Remarks:
*/

class Solution {
   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        TreeNode *res;
        auto treeConstruct = [&](auto treeConstruct, int preI, int preJ, int inI, int inJ) {
            if (preI == preJ) return new TreeNode(preorder[preI]);
            TreeNode *root = new TreeNode(preorder[preI]);
            int tmp = find(inorder.begin(), inorder.end(), preorder[preI]) - inorder.begin();
            int temp = tmp - inI;
            root->left = treeConstruct(treeConstruct, preI + 1, preI + temp, inI, tmp - 1);
            root->right = treeConstruct(treeConstruct, preI + temp + 1, preJ, tmp + 1, inJ);
            return root;
        };
        res = treeConstruct(treeConstruct, 0, n - 1, 0, n - 1);
        return res;
    }
};