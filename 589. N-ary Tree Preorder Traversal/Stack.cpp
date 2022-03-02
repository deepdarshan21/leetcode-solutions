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
   Approach: Stack(Iterative)
       Store element in stack as "root", "root->right", "root->left"

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 35 ms faster than: 44.68%
   Memory Usage: 11.2 MB less than: 76.99%
   Remarks:
*/

class Solution {
   public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<Node*> store;
        store.push(root);
        Node* top;
        while (!store.empty()) {
            top = store.top();
            store.pop();
            ans.push_back(top->val);
            reverse(top->children.begin(), top->children.end());
            for (auto child : top->children) {
                // if(child!=nullptr)
                store.push(child);
            }
        }
        return ans;
    }
};