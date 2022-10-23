#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 31 ms faster than: 44.63%
   Memory Usage: 18.3 MB less than: 5.94%
   Remarks:
*/

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // int n =asteroids.size();
        stack<int> st;
        for (int asteroid : asteroids) {
            st.push(asteroid);
            int temp = st.top();
            st.pop();
            // if(!st.empty() && st.top()>=0 && temp<=0 && abs(st.top())==abs(temp)){
            //     st.pop();
            //     continue;
            // }
            // cout<<temp<<" "<<st.empty()<<endl;
            bool tmp = true;
            while (!st.empty() && st.top() >= 0 && temp <= 0) {
                tmp = true;
                if (abs(st.top()) > abs(temp)) {
                    temp = st.top();
                    st.pop();
                } else if (abs(st.top()) < abs(temp)) {
                    st.pop();
                } else {
                    st.pop();
                    if (!st.empty()) {
                        temp = st.top();
                        st.pop();
                    } else
                        tmp = false;
                }
            }
            if (tmp) st.push(temp);
            // i++;
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};