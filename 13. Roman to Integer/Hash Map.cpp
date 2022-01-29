#include <bits/stdc++.h>
using namespace std;

/* 
    Approach: Unordered Map just for storing data

    Time Complexity: O(n) Space: O(1)        
*/

class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> store;

        store['I'] = 1;
        store['V'] = 5;
        store['X'] = 10;
        store['L'] = 50;
        store['C'] = 100;
        store['D'] = 500;
        store['M'] = 1000;

        int sum = 0, currValue = 0, prevValue = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            currValue = store[s[i]];
            if (prevValue >= currValue)
                sum += currValue;
            else
                sum += currValue - 2 * prevValue;
            prevValue = currValue;
        }
        return sum;
    }
};