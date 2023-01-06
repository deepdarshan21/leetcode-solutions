#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
   Approach: Level Order traversal

   Edge Cases:

   Time Complexity: O(n) Space: O(logn)
   Status: Accepted
   Runtime: 28 ms faster than: 61.6%
   Memory Usage: 17.3 MB less than: 21.6%
   Remarks:
*/

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty() && q.size() > 1) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* tmp = q.front();
                q.pop();
                if (tmp == nullptr) {
                    q.push(nullptr);
                    continue;
                }
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                tmp->next = q.front();
            }
        }
        return root;
    }
};