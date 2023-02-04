#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window
        Make a vector of size 26 to store the frequency of each character in s1.
        Then, make another vector of size 26 to store the frequency of each character
        in s2. Then, iterate over s2 and check if the two vectors are equal. If they
        are, return true. If not, then add the character at the current index to the
        second vector and subtract the character at the current index - n from the
        second vector. Here, n is the size of s1. After the iteration, check if the
        two vectors are equal. If they are, return true. If not, return false.

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 11 ms faster than: 58.98%
   Memory Usage: 7.4 MB less than: 45.48%
   Remarks:
*/

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> storeS1(26, 0), storeS2(26, 0);
        for (int i = 0; i < n; i++) {
            storeS1[s1[i] - 'a']++;
            storeS2[s2[i] - 'a']++;
        }
        for (int i = n; i < m; i++) {
            if (storeS1 == storeS2) return true;
            storeS2[s2[i] - 'a']++;
            storeS2[s2[i - n] - 'a']--;
        }
        return storeS1 == storeS2;
    }
};