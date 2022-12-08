#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Multiset
        First find the first two elements in n^2 time complexity and then use multiset to find next elements
        in logn time complexity.

   Edge Cases:

   Time Complexity: O(n*n*logn) Space: O(1)
   Status: Accepted
   Runtime: 1483 ms faster than: 12%
   Memory Usage: 12 MB less than: 57%
   Remarks:
*/

class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
        multiset<int> a(arr.begin(), arr.end());
        int n = arr.size(), res = 0, temp = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int v = arr[i] + arr[j], u = arr[j];
                while (a.find(v) != a.end()) {
                    temp++;
                    int tmp = v;
                    v = v + u;
                    u = tmp;
                }
                if (temp != 2) res = max(res, temp);
                temp = 2;
            }
        }
        return res;
    }
};