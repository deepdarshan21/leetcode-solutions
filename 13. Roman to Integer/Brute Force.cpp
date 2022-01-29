#include <bits/stdc++.h>
using namespace std;

/* 
    Approach: Brute Force
        1. if next number is smaller then equal to previous number then sum it
        2. if next number is greater then previous number then substract the twice of previous number from 
        current and add it
*/

class Solution {
   public:
    int romanToInt(string s) {
        int sum = 0, currValue, prevValue = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I')
                currValue = 1;
            else if (s[i] == 'V')
                currValue = 5;
            else if (s[i] == 'X')
                currValue = 10;
            else if (s[i] == 'L')
                currValue = 50;
            else if (s[i] == 'C')
                currValue = 100;
            else if (s[i] == 'D')
                currValue = 500;
            else if (s[i] == 'M')
                currValue = 1000;
            if (prevValue >= currValue)
                sum += currValue;
            else
                sum += currValue - 2 * prevValue;
            prevValue = currValue;
        }
        return sum;
    }
};