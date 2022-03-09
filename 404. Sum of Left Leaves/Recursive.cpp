#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
   Approach: BFS
        Go BFS and check is the node is left or not and is it leaf node or not. If both conditions
        fullfills then add that node's val to final result

   Edge Cases: recursion

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 84.34%
   Memory Usage: 13.7 MB less than: 11.97%
   Remarks:
*/

class Solution {
   public:
    int sumOfLeftLeaves(TreeNode *root, bool isLeft = false) {
        int leftSum = 0;
        if (root == nullptr) {
            return leftSum;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (isLeft) {
                return root->val;
            }
            return leftSum;
        } else {
            leftSum += sumOfLeftLeaves(root->left, true);
            leftSum += sumOfLeftLeaves(root->right);
        }
        return leftSum;
    }
};