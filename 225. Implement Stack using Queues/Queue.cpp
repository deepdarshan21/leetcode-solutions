#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Using queue

   Edge Cases:

   Time Complexity: O(n) Space: O(n)
   Status: Accepted
   Runtime:  ms faster than: 100%
   Memory Usage: 6.9 MB less than: 58.10%
   Remarks:
*/

class MyStack {
   private:
    queue<int> main;

   public:
    MyStack() {
    }

    void push(int x) {
        queue<int> help;
        while (!main.empty()) {
            help.push(main.front());
            main.pop();
        }
        main.push(x);
        while (!help.empty()) {
            main.push(help.front());
            help.pop();
        }
    }

    int pop() {
        int temp;
        temp = main.front();
        main.pop();
        return temp;
    }

    int top() {
        return main.front();
    }

    bool empty() {
        return main.empty();
    }
};