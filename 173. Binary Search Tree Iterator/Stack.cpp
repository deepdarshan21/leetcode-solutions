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
   Approach: Stack + revese inorder(right, root, left)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 74 ms faster than: 25.87%
   Memory Usage: 24.2 MB less than: 20.98%
   Remarks:
*/

class BSTIterator {
   private:
    stack<int> st;

   public:
    BSTIterator(TreeNode *root) {
        help(root);
    }

    void help(TreeNode *root) {
        if (root == nullptr) return;
        help(root->right);
        st.push(root->val);
        help(root->left);
    }

    int next() {
        int res = st.top();
        st.pop();
        return res;
    }

    bool hasNext() {
        return !st.empty();
    }
};
