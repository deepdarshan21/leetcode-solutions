#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using Stacks


   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 3 ms faster than: 95.14%
   Memory Usage: 7.9 MB less than: 80.17%
   Remarks:
*/

class Solution {
   public:
    string simplifyPath(string path) {
        stack<string> store;
        string temp = "";
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {
                if (i > 0 && path[i - 1] == '/') {
                    continue;
                }
                if (temp == "..") {
                    if (!store.empty()) {
                        store.pop();
                    }
                } else if (temp == ".") {
                    temp = "";
                } else {
                    store.push(temp);
                }
                temp = "";
            } else {
                temp += path[i];
            }
        }
        if (temp == "..") {
            if (!store.empty()) {
                store.pop();
            }
        } else if (temp == ".") {
            temp = "";
        } else {
            store.push(temp);
        }
        // cout << store.empty() << endl;
        stack<string> reverseStore;
        while (!store.empty()) {
            reverseStore.push(store.top());
            store.pop();
        }
        string res = "";
        while (!reverseStore.empty()) {
            // cout<<"in-"<<store.top()<<endl;
            if (reverseStore.top() == "") {
                reverseStore.pop();
                continue;
            }
            res += "/";
            res += reverseStore.top();
            reverseStore.pop();
        }
        if (res == "") {
            res += "/";
        }
        return res;
    }
};