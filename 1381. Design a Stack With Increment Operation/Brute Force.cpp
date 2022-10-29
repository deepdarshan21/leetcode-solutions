#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 35 ms faster than: 95.62%
   Memory Usage: 21 MB less than: 39.45%
   Remarks:
*/

class CustomStack {
   private:
    vector<int> st;
    int len, i;

   public:
    CustomStack(int maxSize) {
        len = maxSize;
        i = 0;
        st.resize(maxSize);
    }

    void push(int x) {
        if (i < len) {
            st[i] = x;
            i++;
        }
    }

    int pop() {
        if (i == 0) return -1;
        i--;
        return st[i];
    }

    void increment(int k, int val) {
        for (int j = 0; j < min(k, i); j++) st[i] += val;
    }
};