#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Stack
        Remove a digit if its preceding digit is smaller than itself. Follow this step 'k' times

   Edge Cases:
        1. if final step is empty => return "0"
        2. if after traversal on whole array, k not become 0 => remove remaining k elements by "pop"

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 4 ms faster than: 83.64%
   Memory Usage: 7.1 MB less than: 52.75%
   Remarks:
*/

class Solution {
   public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return "0";
        }
        string res = "";
        stack<char> store;
        store.push(num[0]);
        for (int i = 1; i < num.size(); i++) {
            while (k && !store.empty() && num[i] < store.top()) {
                store.pop();
                k--;
            }
            store.push(num[i]);
            if (store.size() == 1 && store.top() == '0') {
                store.pop();
            }
        }
        while (k && !store.empty()) {
            store.pop();
            k--;
        }
        if (store.empty()) {
            return "0";
        }
        while (!store.empty()) {
            res += store.top();
            store.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};