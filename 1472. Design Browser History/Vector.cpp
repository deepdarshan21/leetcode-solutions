#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Vector

   Edge Cases:

   Time Complexity: O(1) Space: O(n)
   Status: Accepted
   Runtime: 159 ms faster than: 87.48%
   Memory Usage: 57.4 MB less than: 82.46%
   Remarks:
*/

class BrowserHistory {
   private:
    vector<string> st;
    int curr;

   public:
    BrowserHistory(string homepage) {
        st.push_back(homepage);
        curr = 0;
    }

    void visit(string url) {
        st.erase(st.begin() + curr + 1, st.end());
        st.push_back(url);
        curr++;
    }

    string back(int steps) {
        curr = steps > curr ? 0 : curr - steps;
        return st[curr];
    }

    string forward(int steps) {
        curr = (curr + steps) < st.size() ? curr + steps : st.size() - 1;
        return st[curr];
    }
};