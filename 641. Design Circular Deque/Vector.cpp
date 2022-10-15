#include <bits/stdc++.h>
using namespace std;

/*
   Approach: Vector

   Edge Cases:

   Time Complexity: O(1) Space: O(n)
   Status: Accepted
   Runtime: 67 ms faster than: 30.67%
   Memory Usage: 16.9 MB less than: 50.36%
   Remarks:
*/

class MyCircularDeque {
   private:
    vector<int> arr;
    int size, cnt, idx;

   public:
    MyCircularDeque(int k) {
        size = k;
        arr.resize(size);
        cnt = 0;
        idx = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        idx = idx == 0 ? size - 1 : idx--;
        arr[idx] = value;
        cnt++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        arr[(idx + cnt) % size] = value;
        cnt++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        idx = (idx + 1) % size;
        cnt--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        cnt--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[idx];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[(idx + cnt - 1) % size];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == size;
    }
};