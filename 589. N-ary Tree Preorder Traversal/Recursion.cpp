#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
   Approach: Recursion
        Preorder-> Root, Left, Right
        => ans = root, preorder(left), preorder(right)

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 29 ms faster than: 60.21%
   Memory Usage: 14.2 MB less than: 12.66%
   Remarks:
*/

class Solution {
   public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        // root
        ans.push_back(root->val);
        // left to right
        for (auto childRoot : root->children) {
            vector<int> temp = preorder(childRoot);
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};