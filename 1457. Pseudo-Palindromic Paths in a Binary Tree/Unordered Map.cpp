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
   Approach:


   Edge Cases:

   Time Complexity: O() Space: O()
   Status: Time Limit Exceeded
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   public:
    int pseudoPalindromicPaths(TreeNode *root) {
        unordered_map<int, int> ump;
        return help(root, ump);
    }

   private:
    int help(TreeNode *root, unordered_map<int, int> ump) {
        if (root == nullptr) {
            return 0;
        } else {
            ump[root->val]++;
        }
        if (root->left != nullptr && root->right != nullptr) {
            return help(root->left, ump) + help(root->right, ump);
        } else if (root->left != nullptr && root->right == nullptr) {
            return help(root->left, ump);
        } else if (root->left == nullptr && root->right != nullptr) {
            return help(root->right, ump);
        } else {
            int odd_count = 0;
            for (auto itr : ump) {
                if (itr.second % 2 == 1) {
                    odd_count++;
                }
                if (odd_count > 1) {
                    return 0;
                }
            }
            return 1;
        }
    }
};