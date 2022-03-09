#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force with hash map
        Use hash map to find the position of the that element in O(1) and then chaeck each element
        must be smaller than its preciding element.

   Edge Cases:

   Time Complexity: O(n^2) Space: O(n)
   Status: Accpeted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 9.7 MB less than: 39.35%
   Remarks:
*/

class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp = createHashMap(order);
        for (int i = 1; i < words.size(); i++) {
            if (!isFirstSmall(words[i - 1], words[i], mp)) {
                return false;
            }
        }
        return true;
    }

   private:
    unordered_map<char, int> createHashMap(string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++) {
            mp[order[i]] = i;
        }
        return mp;
    }
    bool isFirstSmall(string first, string second, unordered_map<char, int>& mp) {
        int i = 0;
        while (i < first.size() && i < second.size()) {
            if (mp[first[i]] < mp[second[i]]) {
                return true;
            } else if (mp[first[i]] > mp[second[i]]) {
                return false;
            }
            i++;
        }
        return true;
    }
};