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
   Approach: Inorder Treversal

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 11 ms faster than: 24%
   Memory Usage: 12 MB less than: 27%
   Remarks:
*/

class Solution {
   public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        if (arr1.size() != arr2.size()) return false;
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    void inorder(TreeNode *root, vector<int> &arr) {
        if (root->left == nullptr && root->right == nullptr) {
            arr.push_back(root->val);
            return;
        }
        if (root->left != nullptr) inorder(root->left, arr);
        if (root->right != nullptr) inorder(root->right, arr);
    }
};