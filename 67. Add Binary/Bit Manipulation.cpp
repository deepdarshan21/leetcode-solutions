#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit manipulation, string

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.3 MB less than: 58.08%
   Remarks:
*/

class Solution {
   public:
    string addBinary(string a, string b) {
        string c = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0, temp1, temp2, temp;
        char res;
        while (i >= 0 || j >= 0) {
            if (i < 0 && j >= 0) {
                temp1 = 0;
                temp2 = b[j] - 48;
                j--;
            } else if (i >= 0 && j < 0) {
                temp1 = a[i] - 48;
                temp2 = 0;
                i--;
            } else if (i >= 0 && j >= 0) {
                temp1 = a[i] - 48;
                temp2 = b[j] - 48;
                i--;
                j--;
            }
            // cout<<temp1<<" "<<temp2<<" "<<carry<<endl;
            temp = temp1 + temp2 + carry;
            // cout<<temp<<endl;
            if (temp == 3) {
                res = 1 + 48;
                carry = 1;
                c += res;
            } else if (temp == 2) {
                res = 0 + 48;
                carry = 1;
                c += res;
            } else if (temp == 1) {
                res = 1 + 48;
                carry = 0;
                c += res;
            } else if (temp == 0) {
                res = 0 + 48;
                carry = 0;
                c += res;
            }
            // cout<<c<<endl;
        }
        if (carry > 0) {
            res = carry + 48;
            c += res;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};