#include <bits/stdc++.h>
using namespace std;

/*
   Approach: use vectors to solve this problem

   Edge Cases:

   Time Complexity: O(1) Space: O(1)
   Status: Acceped
   Runtime: 75 ms faster than: 54.60%
   Memory Usage: 20.1 MB less than: 71.52%
   Remarks:
*/

class FrontMiddleBackQueue {
   private:
    vector<int> arr;

   public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        arr.insert(arr.begin(), val);
        // cout<<arr[0]<<endl;
    }

    void pushMiddle(int val) {
        int mid = arr.size() / 2;
        arr.insert(arr.begin() + mid, val);
        // cout<<arr[0]<<endl;
    }

    void pushBack(int val) {
        arr.push_back(val);
        // cout<<arr[0]<<arr[1]<<endl;
    }

    int popFront() {
        if (arr.size() == 0) return -1;
        int res = arr[0];
        arr.erase(arr.begin());
        return res;
    }

    int popMiddle() {
        if (arr.size() == 0) return -1;
        int mid = arr.size() % 2 == 0 ? arr.size() / 2 - 1 : arr.size() / 2;
        int res = arr[mid];
        // cout<<mid<<endl;
        arr.erase(arr.begin() + mid);
        return res;
    }

    int popBack() {
        if (arr.size() == 0) return -1;
        int res = arr[arr.size() - 1];
        arr.pop_back();
        return res;
    }
};