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
   Approach: Use queue to store the children elements

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 52 ms faster than: 12.75%
   Memory Usage: 11.5 MB less than: 99.18%
   Remarks:
*/

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        int size;
        queue<Node*> store;
        store.push(root);
        Node* temp;
        while (!store.empty()) {
            size = store.size();
            res.push_back(vector<int>());
            for (int i = 0; i < size; i++) {
                temp = store.front();
                store.pop();
                res.back().push_back(temp->val);
                for (auto itr : temp->children) {
                    store.push(itr);
                }
            }
        }
        return res;
    }
};