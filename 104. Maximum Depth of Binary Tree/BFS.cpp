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
        Number o rows in tree is equal to maximum depth of tree

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 8 ms faster than: 80.03%
   Memory Usage: 19 MB less than: 14.55%
   Remarks:
*/

class Solution {
   public:
    int maxDepth(TreeNode *root) {
        int max, size;
        max = 0;
        if (root == nullptr) {
            return max;
        }
        queue<TreeNode *> store;
        store.push(root);
        TreeNode *A;
        while (!store.empty()) {
            size = store.size();
            for (int i = 0; i < size; i++) {
                A = store.front();
                store.pop();
                if (A->left != nullptr) {
                    store.push(A->left);
                }
                if (A->right != nullptr) {
                    store.push(A->right);
                }
            }
            max++;
        }
        return max;
    }
};