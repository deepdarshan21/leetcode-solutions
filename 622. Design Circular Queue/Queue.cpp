#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Queue

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Accepted
   Runtime: 24 ms faster than: 94.41%
   Memory Usage: 17 MB less than: 10.52%
   Remarks:
*/

class MyCircularQueue {
   private:
    queue<int> queue;
    int size;

   public:
    MyCircularQueue(int k) {
        size = k;
    }

    bool enQueue(int value) {
        if (queue.size() == size) return false;
        queue.push(value);
        return true;
    }

    bool deQueue() {
        if (queue.size() == 0) return false;
        queue.pop();
        return true;
    }

    int Front() {
        if (queue.size() == 0) return -1;
        return queue.front();
    }

    int Rear() {
        if (queue.size() == 0) return -1;
        return queue.back();
    }

    bool isEmpty() {
        return queue.size() == 0;
    }

    bool isFull() {
        return queue.size() == size;
    }
};