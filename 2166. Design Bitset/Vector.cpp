#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Vector and precalculation

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 785 ms faster than: 66.87%
   Memory Usage: 198.6 MB less than: 33.93%
   Remarks:
*/

class Bitset {
   private:
    vector<int> bits;
    int n;
    int numOfOnes = 0, flipCount = 0;

   public:
    Bitset(int size) {
        bits.resize(size, 0);
        n = size;
    }

    void fix(int idx) {
        if (flipCount % 2 == 0 && bits[idx] == 0) {
            numOfOnes++;
            bits[idx] = 1;
        }
        if (flipCount % 2 == 1 && bits[idx] == 1) {
            numOfOnes++;
            bits[idx] = 0;
        }
    }

    void unfix(int idx) {
        if (flipCount % 2 == 0 && bits[idx] == 1) {
            numOfOnes--;
            bits[idx] = 0;
        }
        if (flipCount % 2 == 1 && bits[idx] == 0) {
            numOfOnes--;
            bits[idx] = 1;
        }
    }

    void flip() {
        numOfOnes = n - numOfOnes;
        flipCount++;
    }

    bool all() {
        return numOfOnes == n;
    }

    bool one() {
        return numOfOnes > 0;
    }

    int count() {
        return numOfOnes;
    }

    string toString() {
        string res = "";
        for (int i = 0; i < n; i++) {
            if (flipCount % 2 == 1) {
                res += to_string(1 - bits[i]);
            } else {
                res += to_string(bits[i]);
            }
        }
        return res;
    }
};
