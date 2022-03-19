#include <bits/stdc++.h>
using namespace std;

/*
   Approach:

   Edge Cases:

   Time Complexity: O(1) Space: O(n)
   Status: Accepted
   Runtime: 216 ms faster than: 86.29%
   Memory Usage: 97.1 MB less than: 61.22%
   Remarks:
*/

class RandomizedSet {
   private:
    map<int, int> mp;  // non zero if element is present
    vector<int> set;

   public:
    RandomizedSet() {
        // set.push_back(0);
    }

    bool insert(int val) {
        if (mp.count(val)) return false;

        mp[val] = set.size();
        set.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!(mp.count(val))) return false;

        int index = mp[val];
        mp[set.back()] = index;
        swap(set[index], set.back());

        set.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return set[rand() % set.size()];
    }
};
