#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
   Approach: BFS

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 8 ms faster than: 32%
   Memory Usage: 8.7 MB less than: 65%
   Remarks:
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        vector<bool> vis(101, false);
        unordered_map<int, Node*> store;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* currNode = q.front();
            q.pop();
            if (store.count(currNode->val) == 0) store[currNode->val] = new Node(currNode->val);
            for (auto itr : currNode->neighbors) {
                if (store.count(itr->val)) store[itr->val] = new Node(itr->val);
                store[currNode->val]->neighbors.push_back(store[itr->val]);
                q.push(itr);
            }
            vis[currNode->val] = true;
        }
        return store[1];
    }
};