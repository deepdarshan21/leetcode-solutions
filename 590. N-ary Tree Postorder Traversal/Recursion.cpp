#include <bits/stdc++.h>
using namespace std;

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
   Approach: Use normal recusion to print in postorder

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 56 ms faster than: 10.91%
   Memory Usage: 11.5 MB less than: 18.12%
   Remarks:
*/

class Solution {
   public:
    vector<int> postorder(Node* root) {
        help(root);
        return store;
    }

   private:
    vector<int> store;
    void help(Node* root) {
        if (root == nullptr) {
            return;
        }
        for (auto itr : root->children) {
            help(itr);
        }
        store.push_back(root->val);
    }
};