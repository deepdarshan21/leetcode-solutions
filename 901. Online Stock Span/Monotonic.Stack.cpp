#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Monotonic Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 545 ms faster than: 17.37%
   Memory Usage: 84.3 MB less than: 23.52%
   Remarks:
*/

class StockSpanner {
   private:
    stack<pair<int, int>> st;

   public:
    StockSpanner() {}

    int next(int price) {
        int res = 1;
        while (!st.empty() && st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }
        st.push({price, res});
        return res;
    }
};