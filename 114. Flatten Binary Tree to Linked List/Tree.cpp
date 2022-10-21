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
   Approach: Opposite of pre order

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 20 ms faster than: 8.75%
   Memory Usage: 12.7 MB less than: 77.11%
   Remarks:
*/

class Solution {
   public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};