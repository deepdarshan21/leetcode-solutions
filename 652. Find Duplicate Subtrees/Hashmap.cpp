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
   Approach: Hashmap
    Convert the tree into string and then use the concept of maps to count the freq of number of times
    a tree repeats

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 90 ms faster than: 28.15%
   Memory Usage: 63.1 MB less than: 23.23%
   Remarks:
*/

class Solution {
   public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        vector<TreeNode *> res;
        DFS(root, res);
        return res;
    }

   private:
    unordered_map<string, int> store;
    string DFS(TreeNode *root, vector<TreeNode *> &res) {
        if (root == nullptr) {
            return ":";
        }
        string s = to_string(root->val) + ", " + DFS(root->left, res) + " , " + DFS(root->right, res);
        store[s]++;
        if (store[s] == 2) {
            res.push_back(root);
        }
        return s;
    }
};