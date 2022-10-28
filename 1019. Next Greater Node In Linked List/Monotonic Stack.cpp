#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
   Approach: Monotonic Stack Implementation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Acccepted
   Runtime: 217 ms faster than: 51.49%
   Memory Usage: 43.1 MB less than: 21.03%
   Remarks:
*/

class Solution {
   public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> res, arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        res.resize(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};