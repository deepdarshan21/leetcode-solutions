#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 50 ms faster than: 50.95%
   Memory Usage: 14 MB less than: 39.16%
   Remarks:
*/

class Solution {
   private:
    struct Log {
        int id;
        string status;
        int timestamp;
    };

   public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<Log> st;
        int initial = 0;
        for (string log : logs) {
            stringstream ss(log);
            string temp1, temp2, temp3;
            getline(ss, temp1, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');
            Log item = {stoi(temp1), temp2, stoi(temp3)};
            if (item.status == "start") {
                if (!st.empty()) res[st.top().id] += item.timestamp - initial;
                initial = item.timestamp;
                st.push(item);
            } else {
                if (st.top().id == item.id) {
                    res[item.id] += item.timestamp - initial + 1;
                    initial = item.timestamp + 1;
                    st.pop();
                }
            }
        }
        return res;
    }
};