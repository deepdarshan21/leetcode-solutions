#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/*
   Approach: Divide and Conquer
        Use recursion to divide the grid into 4 subgrids and check if all elements are the same.
        If so, return a new node with the value of the element and isLeaf = true.
        Otherwise, return a new node with isLeaf = false and recursively construct the 4 subgrids.

   Edge Cases:

   Time Complexity: O(n*n) Space: O(n)
   Status: Accepted
   Runtime: 14 ms faster than: 73.45%
   Memory Usage: 16.2 MB less than: 32.61%
   Remarks:
*/

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
    Node* construct(vector<vector<int>>& grid, int x, int y, int n) {
        // check if all elements are the same
        bool same = true;
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (grid[i][j] != grid[x][y]) {
                    same = false;
                    break;
                }
            }
        }
        if (same) {
            return new Node(grid[x][y] == 1, true);
        }
        Node* topLeft = construct(grid, x, y, n / 2);
        Node* topRight = construct(grid, x, y + n / 2, n / 2);
        Node* bottomLeft = construct(grid, x + n / 2, y, n / 2);
        Node* bottomRight = construct(grid, x + n / 2, y + n / 2, n / 2);
        return new Node(topLeft->val, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};