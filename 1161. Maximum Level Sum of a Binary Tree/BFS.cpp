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
   Approach: BFS
        Apply BFS and traverse level wise and store the maxValue of a level

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 407 ms faster than: 6.23%
   Memory Usage: 107.1 MB less than: 82.20%
   Remarks:
*/

class Solution {
   public:
    int maxLevelSum(TreeNode *root) {
        int maxValue = INT_MIN, ansLevel, level = 1;
        queue<TreeNode *> store;
        store.push(root);
        while (!store.empty()) {
            int n = store.size();
            int sumLevel = 0;
            TreeNode *temp;
            for (int i = 0; i < n; i++) {
                temp = store.front();
                store.pop();
                sumLevel += temp->val;
                if (temp->left != nullptr) {
                    store.push(temp->left);
                }
                if (temp->right != nullptr) {
                    store.push(temp->right);
                }
            }
            if (maxValue < sumLevel) {
                maxValue = sumLevel;
                ansLevel = level;
            }
            level++;
        }
        return ansLevel;
    }
};