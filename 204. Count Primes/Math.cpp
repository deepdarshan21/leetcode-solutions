#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 183 ms faster than: 90.81%
   Memory Usage: 10.4 MB less than: 34.29%
   Remarks:
*/

class Solution {
   public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for (int i = 2; i <= sqrt(n); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int res = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i]) res++;
        return res;
    }
};