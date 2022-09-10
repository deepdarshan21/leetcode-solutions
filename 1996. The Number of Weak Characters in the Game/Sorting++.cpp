#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Sorting
        Sort the given array such that first element of one is smaller than other's first element.
        If both's first element is same then sorting in decreasing order of second element.
        Start from left and monitor the maximum defence(i.e second)

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 1493 ms faster than: 14.55%
   Memory Usage: 125.1 MB less than: 70.70%
   Remarks:
*/

class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int n = properties.size();
        int defence_max = INT_MIN, res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (defence_max > properties[i][1]) {
                res++;
            }
            defence_max = max(defence_max, properties[i][1]);
        }
        return res;
    }
};