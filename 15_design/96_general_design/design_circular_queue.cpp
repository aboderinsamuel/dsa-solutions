#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int rear;
    int front;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        size = 0;
    }
    bool enQueue(int value) {
        if (isFull()) return false;
        q[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }
    // in here deque doesn't have anything in it, so we just move the front pointer forward and decrease the size of the queue.
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }
    int Rear() {
        if (isEmpty()) return -1;
        return q[(rear - 1 + capacity) % capacity];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
};