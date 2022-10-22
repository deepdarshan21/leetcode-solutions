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
   Approach: Tree

   Edge Cases:

   Time Complexity: O(n*2) Space: O(logn)
   Status: Accepted
   Runtime: 170 ms faster than: 38.41%
   Memory Usage: 42.2 MB less than: 45.12%
   Remarks:
*/

class Solution {
   public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        int n = nums.size();
        return help(nums, 0, n);
    }
    TreeNode *help(vector<int> &nums, int low, int high) {
        TreeNode *root;
        if (low == high) return nullptr;
        int maxi = low;
        for (int i = low; i < high; i++) {
            if (nums[i] > nums[maxi]) maxi = i;
        }
        root = new TreeNode(nums[maxi]);
        root->left = help(nums, low, maxi);
        root->right = help(nums, maxi + 1, high);
        return root;
    }
};