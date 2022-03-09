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

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 84.34%
   Memory Usage: 13.7 MB less than: 11.97%
   Remarks:
*/

class Solution {
   public:
    int sumOfLeftLeaves(TreeNode *root) {
        int leftSum = 0;
        if (root == nullptr) {
            return leftSum;
        }
        queue<TreeNode *> store;
        TreeNode *temp;
        store.push(root);
        while (!store.empty()) {
            temp = store.front();
            store.pop();
            if (temp->left != nullptr) {
                if (temp->left->left == nullptr && temp->left->right == nullptr) {
                    leftSum += temp->left->val;
                }
                store.push(temp->left);
            }
            if (temp->right != nullptr) {
                store.push(temp->right);
            }
        }
        return leftSum;
    }
};