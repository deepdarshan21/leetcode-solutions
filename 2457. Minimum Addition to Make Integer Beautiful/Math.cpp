#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Math


   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 3 ms faster than: 84.21%
   Memory Usage: 6 MB less than: 36.84%
   Remarks:
*/

class Solution {
   public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long res = 0;
        if (digitSum(n) <= target) return res;
        long long i = 1;
        while (i < 1e12 + 1) {
            long long temp = (long long)ceil((double)n / i) * i;
            // cout<<temp<<endl;
            if (digitSum(temp) <= target) {
                res = temp - n;
                break;
            }
            i *= 10;
        }
        return res;
    }
    int digitSum(long long num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        // cout<<"Sum "<< sum<<endl;
        return sum;
    }
};