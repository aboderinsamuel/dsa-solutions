#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> dq;
    int rear;
    int front;
    int size;
    int capacity;
public:
    MyCircularDeque(int k) {
        dq.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        size = 0;
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        //in normal queue, we insert at rear, but in deque, we can insert at front as well. So we need to move front pointer backward and insert the value at front.
        //also, front declaration comes first before dq[front] = value; because we need to move front pointer first before inserting the value at front.
        dq[front] = value;
        size++;
        return true;
    }
    bool insertLast(int value) {
        if (isFull()) return false;
        dq[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    int getFront() {
        if (isEmpty()) return -1;
        return dq[front];
    }
    int getRear() {
        if (isEmpty()) return -1;
        return dq[(rear - 1 + capacity) % capacity];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
};