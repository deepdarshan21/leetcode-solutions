#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

/*
   Approach: Inorder Treversal

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 10 ms faster than: 56.52%
   Memory Usage: 11 MB less than: 23.41%
   Remarks:
*/

class Solution {
   public:
    int maxAncestorDiff(TreeNode *root) {
        return inorder(root, {INT_MIN, INT_MAX});
    }
    int inorder(TreeNode *root, pair<int, int> minmax) {
        if (root->val > minmax.first) minmax.first = root->val;
        if (root->val < minmax.second) minmax.second = root->val;
        // cout<<minmax.first<<" "<<minmax.second<<endl;
        int temp = abs(minmax.first - minmax.second);
        if (root->left == nullptr && root->right == nullptr) {
            return temp;
        }

        int temp1, temp2;
        if (root->left != nullptr) temp1 = inorder(root->left, minmax);
        if (root->right != nullptr) temp2 = inorder(root->right, minmax);
        return max({temp, temp1, temp2});
    }
};