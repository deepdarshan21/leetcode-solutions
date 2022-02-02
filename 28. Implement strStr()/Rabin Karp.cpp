#include <bits/stdc++.h>
using namespace std;

/*
    Approach: Rabin Karp
       First compare hash code of pattern size substring from haystack string, if hash code matchs
       then match that substring with pattern.

   Edge Cases:
       1. needle is of size 0
       2. haystack is smaller in size then needle

   Time Complexity: O(m+n) Space: O(1)
*/

class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        return rabinKarp(haystack, needle);
    }

   private:
    const int d = 26;
    const int q = 101;
    int rabinKarp(string text, string pattern) {
        int m = text.size(), n = pattern.size(), p = 0, t = 0, h = 1;
        // Hash value of pattern and first slide of text
        for (int i = 0; i < n; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }
        // value of h=pow(d, n-1)%q
        // or
        for (int i = 0; i < n - 1; i++) {
            h = h * d % q;
        }

        for (int i = 0; i <= m - n; i++) {
            if (p == t) {
                if (match(text.substr(i, n), pattern)) {
                    return i;
                }
            } else {
                // faster way to find next slide value
                t = (d * (t - text[i] * h) + text[i + n]) % q;
                if (t < 0) {
                    t += q;
                }
            }
        }
        return -1;
    }
    bool match(string toMatch, string pattern) {
        for (int i = 0; i < pattern.size(); i++) {
            if (toMatch[i] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};