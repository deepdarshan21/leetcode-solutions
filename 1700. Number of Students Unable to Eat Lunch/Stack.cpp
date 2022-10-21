#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Queue

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 6 ms faster than: 44.02%
   Memory Usage: 8.9 MB less than: 30.29%
   Remarks:
*/

class Solution {
   public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        // reverse(students.begin(), students.end());
        for (int student : students) st.push(student);
        int temp = st.size();
        int i = 0;
        // cout<<st.front()<<endl;
        while (!st.empty() && temp != 0) {
            // cout<<"Check: "<<st.front()<<endl;
            if (sandwiches[i] == st.front()) {
                st.pop();
                i++;
                temp = st.size();
            } else {
                st.push(st.front());
                st.pop();
                temp--;
            }
        }
        return st.size();
    }
};