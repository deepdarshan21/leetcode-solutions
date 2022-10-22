#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack Pair
        Store the min till that point in stack with "val"

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 74 ms faster than: 5.70%
   Memory Usage: 16.4 MB less than: 30.59%
   Remarks:
*/

class MinStack {
   private:
    stack<pair<int, int>> st;

   public:
    MinStack() {
    }

    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(st.top().second, val)});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};