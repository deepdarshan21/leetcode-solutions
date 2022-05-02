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
   Approach: Binary Search like

   Edge Cases:

   Time Complexity: O(logn) Space: O(1)
   Status: Accepted
   Runtime: 57 ms faster than: 20.17%
   Memory Usage: 30.9 MB less than: 22.29%
   Remarks:
*/

class Solution {
   public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int height = 0;
        height = leftHeight(root);

        int count, tempCount = 0;
        count = pow(2, height);

        while (root != nullptr) {
            height--;
            if (height == leftHeight(root->right)) {
                tempCount += pow(2, height);
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return count + tempCount;
    }
    int leftHeight(TreeNode *root) {
        int height = 0;
        while (root != nullptr) {
            height++;
            root = root->left;
        }
        return height - 1;
    }
};