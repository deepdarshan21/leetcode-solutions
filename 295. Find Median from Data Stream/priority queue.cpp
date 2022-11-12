#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Priority Queue
        Make two seperate lists

   Edge Cases:

   Time Complexity: O(nlogn) Space: O(n)
   Status: Accepted
   Runtime: 846 ms faster than: 15.14%
   Memory Usage: 117 MB less than: 88.90%
   Remarks:
*/

class MedianFinder {
   private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

   public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (small.empty() || small.top() > num)
            small.push(num);
        else
            large.push(num);

        if (small.size() > (large.size() + 1)) {
            large.push(small.top());
            small.pop();
        }

        if (large.size() > (small.size() + 1)) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) return small.top();
        if (large.size() > small.size()) return large.top();
        return (small.top() + large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */