#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
   Approach: Tree cunstruction from inorder and postorder traversal

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 16 ms faster than: 80.57%
   Memory Usage: 26.5 MB less than: 25.72%
   Remarks:
*/

class Solution {
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> s1;
        for (int i = 0; i < inorder.size(); i++) s1[inorder[i]] = i;

        auto buildTree = [&](auto self, int l1, int r1, int l2, int r2) -> TreeNode* {
            if (l1 > r1) return nullptr;
            TreeNode* root = new TreeNode(postorder[r2]);
            int mid = s1[postorder[r2]];
            root->left = self(self, l1, mid - 1, l2, l2 + mid - l1 - 1);
            root->right = self(self, mid + 1, r1, l2 + mid - l1, r2 - 1);
            return root;
        };
        return buildTree(buildTree, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};