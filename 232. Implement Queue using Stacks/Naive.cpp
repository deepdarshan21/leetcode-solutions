#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Brute Force
        Use two stacks one for help and onre operations. Use help stack to convert
        "queue" stack to queue

   Edge Cases:

   Time Complexity: O(n) Space: O(1)
   Status: Accepted
   Runtime: 0 ms faster than: 100%
   Memory Usage: 6.9 MB less than: 87.79%
   Remarks:
*/

class MyQueue {
   private:
    stack<int> queue, help;

   public:
    MyQueue() {
    }

    void push(int x) {
        while (!queue.empty()) {
            help.push(queue.top());
            queue.pop();
        }
        help.push(x);
        while (!help.empty()) {
            queue.push(help.top());
            help.pop();
        }
    }

    int pop() {
        if (queue.empty()) {
            return 0;
        }
        queue.pop();
        return 1;
    }

    int peek() {
        return queue.top();
    }

    bool empty() {
        return queue.empty();
    }
};