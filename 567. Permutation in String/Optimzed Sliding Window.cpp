#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sliding Window

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 5 ms faster than: 83.79%
   Memory Usage: 7.3 MB less than: 74.79%
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
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (storeS1[i] == storeS2[i]) count++;
        }
        for (int i = n; i < m; i++) {
            if (count == 26) return true;
            int left = s2[i - n] - 'a';
            int right = s2[i] - 'a';
            storeS2[right]++;
            if (storeS2[right] == storeS1[right])
                count++;
            else if (storeS2[right] == storeS1[right] + 1)
                count--;
            storeS2[left]--;
            if (storeS2[left] == storeS1[left])
                count++;
            else if (storeS2[left] == storeS1[left] - 1)
                count--;
        }
        return count == 26;
    }
};