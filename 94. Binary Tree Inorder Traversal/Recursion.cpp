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
   Approach: Inorder traversal using recursion


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 10.5 MB less than: 6.07%
   Remarks:
*/

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        store.push_back(root->val);
        inorderTraversal(root->right);
        return store;
    }

   private:
    vector<int> store;
};