#include <bits/stdc++.h>
using namespace std;

/*
   Approach: HashMap(unordered_map)
        In push function:
            First count the freq of element in tha "stack"
            Than put the element to its corresponding freq in its order.
        In pop function:
            Pop the element which has highest freq

   Edge Cases:

   Time Complexity: O(1) Space: O(n)
   Status: Accepted
   Runtime: 148 ms faster than: 99.92%
   Memory Usage: 79.8 MB less than: 84.88%
   Remarks:
*/

class Solution {
   private:
    int maxCount;
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> freqElement;

   public:
    FreqStack() {
        maxCount = 0;
        freq.clear();
        freqElement.clear();
    }

    void push(int val) {
        freq[val]++;
        maxCount = max(maxCount, freq[val]);
        freqElement[freq[val]].push_back(val);
    }

    int pop() {
        int returnVal;
        returnVal = freqElement[maxCount][freqElement[maxCount].size() - 1];
        freqElement[maxCount].pop_back();
        if (freqElement[maxCount].size() == 0) {
            maxCount--;
        }
        freq[returnVal]--;
        return returnVal;
    }
};