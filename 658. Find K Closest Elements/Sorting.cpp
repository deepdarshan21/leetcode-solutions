#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force(Sorting)
        Firstly take the store vector to store the differece of element from x and index of element,
        then sort the vector according to difference and index(at second priority).
        Then take the first k elements from that vector and sort them to give answer.

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(1)
   Status: Accepted
   Runtime: 128 ms faster than: 19.03%
   Memory Usage: 36.8 MB less than: 14.93%
   Remarks:
*/

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> store;
        for (int i = 0; i < arr.size(); i++) {
            store.push_back({abs(arr[i] - x), i});
        }
        sort(arr.begin(), arr.end());
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = arr[store[i].second];
        }
        return res;
    }
};