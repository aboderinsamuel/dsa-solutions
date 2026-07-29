#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left; // max heap

    priority_queue<int, vector<int>, greater<int>> right; // min heap

public:
    MedianFinder() {}

    void addNum(int num) {

        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;

        if (left.size() > right.size())
            return left.top();

        return right.top();
    }
};