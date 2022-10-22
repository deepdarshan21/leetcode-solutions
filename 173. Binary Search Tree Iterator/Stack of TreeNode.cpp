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
   Approach: Stack of TreeNode
        Store the left most in stack and then go to right of stacks.top() treenode

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 83 ms faster than: 13.09%
   Memory Usage: 24.2 MB less than: 54.96%
   Remarks:
*/

class BSTIterator {
   private:
    stack<TreeNode *> st;
    void pushLeft(TreeNode *root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

   public:
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    int next() {
        TreeNode *res = st.top();
        st.pop();
        pushLeft(res->right);
        return res->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};