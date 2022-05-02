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
   Approach: Inorder tree traversal

   Edge Cases:

   Time Complexity: O(n) Space: O(log n)
   Status: Accepted
   Runtime: 27 ms faster than: 95.03%
   Memory Usage: 30.8 MB less than: 64.98%
   Remarks:
*/

class Solution {
   public:
    int countNodes(TreeNode *root) {
        int count = 0;
        count = recursion(root, count);
        return count;
    }
    int recursion(TreeNode *root, int count) {
        // cout<<count<<endl;
        if (root == nullptr) {
            return 0;
        }
        int temp = count;
        count += recursion(root->left, temp);
        count++;
        count += recursion(root->right, temp);
        // cout<<"Last"<<" "<<count<<endl;
        return count;
    }
};