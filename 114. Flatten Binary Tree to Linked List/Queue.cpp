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
   Approach: Traverse tree and store it in queue and then make linked list

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 17 ms faster than: 18.27%
   Memory Usage: 13 MB less than: 5.38%
   Remarks:
*/

class Solution {
   public:
    queue<int> q;
    void flatten(TreeNode *root) {
        TreeNode *temp = root;
        preOrder(root);
        while (!q.empty()) {
            // if(temp==nullptr) temp = new TreeNode();
            temp->val = q.front();
            // cout<<q.front()<<endl;
            temp->left = nullptr;
            if (q.size() > 1 && temp->right == nullptr) temp->right = new TreeNode();
            temp = temp->right;
            q.pop();
        }
    }
    void preOrder(TreeNode *root) {
        if (root == nullptr) return;
        q.push(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};