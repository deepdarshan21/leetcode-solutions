#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
   public:  // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool
    isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &
    getList() const;
};

/*
   Approach: DFS
        Simply run the loop on given vector,
        if current element is integer than add that to flatten list,
        if current element is list then repeat that process for that list

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime: 22 ms faster than: 41.71%
   Memory Usage: 14.8 MB less than: 25.30%
   Remarks:
*/

class NestedIterator {
   private:
    vector<int> flattenedList;
    int curr, size;
    void helper(NestedInteger &value) {
        if (value.isInteger()) {
            flattenedList.push_back(value.getInteger());
        } else {
            for (auto itr : value) {
                helper(itr);
            }
        }
    }

   public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto itr : nestedList) {
            helper(itr);
        }
        curr = 0;
        size = nestedList.size();
    }

    int next() {
        return flattenedList[curr];
    }

    bool hasNext() {
        return curr < size;
    }
};