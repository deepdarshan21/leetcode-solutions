#include <bits/stdc++.h>
using namespace std;

/*
   Approach: HashSet
        Use hashset to find frequecy of each element while poping from the stack

   Edge Cases:

   Time Complexity: O() Space: O()
   Status:
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks:
*/

class Solution {
   private:
    vector<int> st;

   public:
    FreqStack() {
    }

    void push(int val) {
        st.push_back(val);
    }

    int pop() {
        int max = 0, max_i;
        unordered_map<int, int> mp;
        for (int i = 0; i < st.size(); i++) {
            mp[st[i]]++;
            if (mp[st[i]] >= max) {
                max = mp[st[i]];
                max_i = i;
            }
        }
        int returnVal = st[max_i];
        st.erase(st.begin() + max_i);
        return returnVal;
    }
};