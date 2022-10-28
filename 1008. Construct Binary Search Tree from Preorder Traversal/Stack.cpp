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
   Approach: Stack
        Idea is simple.
            First item in preorder list is the root to be considered.
            For next item in preorder list, there are 2 cases to consider:
                If value is less than last item in stack, it is the left child of last item.
                If value is greater than last item in stack, pop it.
                    The last popped item will be the parent and the item will be the right child of the parent.

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 12 ms faster than: 34.30%
   Memory Usage: 12.8 MB less than: 92.19%
   Remarks:
*/

class Solution {
   public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int n = preorder.size(), i = 0;
        TreeNode *root = nullptr;
        stack<TreeNode *> st;
        if (i < n) {
            root = new TreeNode(preorder[i]);
            st.push(root);
            i++;
        }
        while (i < n) {
            if (st.top()->val > preorder[i]) {
                TreeNode *left = new TreeNode(preorder[i]);
                st.top()->left = left;
                st.push(left);
            } else {
                TreeNode *last = nullptr;
                while (!st.empty() && st.top()->val < preorder[i]) {
                    last = st.top();
                    st.pop();
                }
                TreeNode *right = new TreeNode(preorder[i]);
                last->right = right;
                st.push(right);
            }
            i++;
        }
        return root;
    }
};