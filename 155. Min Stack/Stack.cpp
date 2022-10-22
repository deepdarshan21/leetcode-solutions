#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack and map(not unordered)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 87 ms faster than: 5.01%
   Memory Usage: 17.3 MB less than: 5.41%
   Remarks:
*/

class MinStack {
   private:
    stack<int> st;
    map<int, int> mp;

   public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        mp[val]++;
    }

    void pop() {
        if (mp[st.top()] > 1)
            mp[st.top()]--;
        else
            mp.erase(st.top());
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mp.begin()->first;
    }
};