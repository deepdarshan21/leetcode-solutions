#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Bit manipulation
        Use bit manipulation to make corresponding number and then use that number to compare;
        In making corresponding number use base 4 as there are only four possible letter in string

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 99 ms faster than: 63.55%
   Memory Usage: 16.8 MB less than: 90.09%
   Remarks:
*/

class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> charToNum;
        charToNum['A'] = 0;
        charToNum['C'] = 1;
        charToNum['G'] = 2;
        charToNum['T'] = 3;
        int n = s.size();
        vector<unsigned long long> store(n + 1);
        store[0] = 0;
        for (int i = 0; i < n; i++) {
            store[i + 1] = store[i] * 4 + charToNum[s[i]];
        }
        vector<string> res;
        unordered_map<int, int> freq;
        int power = pow(4, 10);
        for (int i = 0; i < (n - 9); i++) {
            long long temp = store[i + 10] - store[i] * power;
            freq[temp]++;
            if (freq[temp] == 2) res.push_back(s.substr(i, 10));
        }
        return res;
    }
};