#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 9 ms faster than: 58.18%
   Memory Usage: 9.1 MB less than: 23.23%
   Remarks:
*/

class Solution {
   public:
    int compress(vector<char>& chars) {
        int res = 0, count = 0, idx = 0;
        vector<char> help;
        int j = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] == chars[idx])
                count++;
            else {
                if (count == 1) {
                    res++;
                    help.push_back(chars[idx]);
                    j++;
                } else {
                    res++;
                    help.push_back(chars[idx]);
                    j++;
                    int temp = 0;
                    // cout<<count<<endl;
                    while (count != 0) {
                        char temp1 = 48 + count % 10;
                        help.insert(help.begin() + j, temp1);
                        count /= 10;
                        temp++;
                    }
                    j += temp;
                    res += temp;
                }
                idx = i;
                count = 1;
            }
        }
        if (count == 1) {
            res++;
            help.push_back(chars[idx]);
            j++;
        } else {
            res++;
            help.push_back(chars[idx]);
            j++;
            int temp = 0;
            // cout<<count<<endl;
            while (count != 0) {
                char temp1 = 48 + count % 10;
                help.insert(help.begin() + j, temp1);
                count /= 10;
                temp++;
            }
            j += temp;
            res += temp;
        }
        chars.erase(chars.begin(), chars.end());
        for (char x : help) {
            chars.push_back(x);
        }
        return res;
    }
};