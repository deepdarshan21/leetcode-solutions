#include <bits/stdc++.h>
using namespace std;

/*
   Approach: String Manipulation + Binary Search

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Runtime Error
   Runtime:  ms faster than: %
   Memory Usage:  MB less than: %
   Remarks: Stack overflow
*/

class Solution {
   public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        string str1 = "", str2 = "";
        for (int i = 0; i < n1; i++) str1 += s1;
        for (int i = 0; i < n2; i++) str2 += s2;

        function<bool(int)> help = [&](int m) -> bool {
            string str = "";
            for (int i = 0; i < m; i++) str += str2;
            int i = 0, j = 0;
            while (j < str.size() && i < str1.size()) {
                if (str1[i] == str[j]) j++;
                i++;
            }
            return j == str.size() ? true : false;
        };

        int i = 0,
            j = 0;
        while (j < str2.size()) {
            if (str1[i] == str2[j]) j++;
            i++;
        }
        int low = 1, high = 1e5, mid;

        while (low < high) {
            mid = low + (high - low) / 2;
            if (help(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};