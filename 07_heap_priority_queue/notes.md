# Heap Interview Patterns (C++ Cheatsheet)

This README explains the 4 most important heap patterns used in coding interviews, with full working C++ examples.

---

# 1. Largest Element Repeatedly → Max Heap

## Idea

Always extract the **maximum element**.

## Data Structure

```cpp
priority_queue<int>
```

## Example Problem

Sort numbers in descending order using a heap.

## Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<int> nums = {5, 1, 9, 3, 7};
    priority_queue<int> pq;

    for (int num : nums) {
        pq.push(num);
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
```

## Output

```
9 7 5 3 1
```

---

# 2. Smallest Element Repeatedly → Min Heap

## Idea

Always extract the **minimum element**.

## Data Structure

```cpp
priority_queue<int, vector<int>, greater<int>>
```

## Example Problem

Sort numbers in ascending order using a heap.

## Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<int> nums = {5, 1, 9, 3, 7};
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : nums) {
        pq.push(num);
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
```

## Output

```
1 3 5 7 9
```

---

# 3. Kth Largest Element (Stream) → Min Heap of Size K

## Idea

Keep only the **k largest elements**.
The smallest among them is the **kth largest overall**.

## Problem

Design a structure that returns kth largest after each insertion.

## Code

```cpp
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
```

## Key Insight

* Keep heap size = k
* Root = kth largest

---

# 4. Kth Smallest Element → Max Heap of Size K

## Idea

Keep only the **k smallest elements**.
The largest among them is the **kth smallest overall**.

## Code

```cpp
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}
```

## Key Insight

* Keep heap size = k
* Root = kth smallest

---

# Summary Cheat Sheet

| Goal               | Heap Type          |
| ------------------ | ------------------ |
| Get max repeatedly | Max Heap           |
| Get min repeatedly | Min Heap           |
| Kth largest        | Min Heap of size k |
| Kth smallest       | Max Heap of size k |
| Top K largest      | Min Heap of size k |
| Top K smallest     | Max Heap of size k |

---

# Core Interview Rule

If you see:

* "repeated max/min"
* "top K"
* "kth element in stream"

👉 Think **HEAP immediately**