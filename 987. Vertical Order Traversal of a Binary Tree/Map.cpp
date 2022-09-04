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
   Approach: Mapping
        Firstly do simple traversal over the tree and store the value of node at corsponding
        row and col. For storeing use maps as they store in sorted order.

   Edge Cases:

   Time Complexity: O(n*logn*logn*logn) Space: O(1)
   Status: Accepeted
   Runtime: 8 ms faster than: 58.22%
   Memory Usage: 14.6 MB less than: 13.71%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        traverseTree(root, 0, 0);
        vector<vector<int>> res;
        for (auto itr1 : store) {
            res.push_back(vector<int>());
            for (auto itr2 : itr1.second) {
                sort(itr2.second.begin(), itr2.second.end());
                for (auto itr3 : itr2.second) {
                    res.back().push_back(itr3);
                }
            }
        }
        return res;
    }

   private:
    map<int, map<int, vector<int>>> store;
    void traverseTree(TreeNode *root, int col, int row) {
        if (root == nullptr) {
            return;
        }
        store[col][row].push_back(root->val);
        traverseTree(root->left, col - 1, row + 1);
        traverseTree(root->right, col + 1, row + 1);
    }
};