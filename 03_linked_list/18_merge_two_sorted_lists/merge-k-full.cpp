//
// Created by USER on 5/22/2026.
//
#include <iostream>
#include <vector>
#include <queue>

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ============================================================================
// STRATEGY 1: DIVIDE AND CONQUER SOLUTION
// ============================================================================
class DivideAndConquerSolution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int k = lists.size();
        while (k > 1) {
            for (int i = 0; i < k / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2;
        }
        return lists[0];
    }
};

// ============================================================================
// STRATEGY 2: MIN-HEAP / PRIORITY QUEUE SOLUTION
// ============================================================================
class MinHeapSolution {
struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val; // Min-heap behavior
    }
};

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> minHeap;

        for (ListNode* head : lists) {
            if (head) minHeap.push(head);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};

// ============================================================================
// IDE TESTING UTILITIES
// ============================================================================
ListNode* createList(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* curr = &dummy;
    for (int val : values) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    if (!head) {
        std::cout << "[]\n";
        return;
    }
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << " -> nullptr\n";
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper to deep copy a list so we can run both strategies on identical nodes
ListNode* copyList(ListNode* head) {
    if (!head) return nullptr;
    ListNode dummy;
    ListNode* curr = &dummy;
    while (head) {
        curr->next = new ListNode(head->val);
        curr = curr->next;
        head = head->next;
    }
    return dummy.next;
}

// ============================================================================
// MAIN EXECUTION CONTEXT
// ============================================================================
int main() {
    // Define structural input representation: [[1,4,5], [1,3,4], [2,6]]
    std::vector<std::vector<int>> inputData = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    std::cout << "--- Initializing k-Sorted Lists ---\n";
    std::vector<ListNode*> listsForStrategy1;
    std::vector<ListNode*> listsForStrategy2;

    for (const auto& vec : inputData) {
        ListNode* original = createList(vec);
        printList(original);

        // Strategy 1 consumes and alters the lists in-place, so we provide discrete instances
        listsForStrategy1.push_back(original);
        listsForStrategy2.push_back(copyList(original));
    }
    std::cout << "-----------------------------------\n\n";

    // 1. Execute and Profile Divide & Conquer Strategy
    DivideAndConquerSolution dcSolver;
    ListNode* dcResult = dcSolver.mergeKLists(listsForStrategy1);
    std::cout << "Strategy 1 (Divide & Conquer) Output:\n";
    printList(dcResult);

    // 2. Execute and Profile Min-Heap Strategy
    MinHeapSolution heapSolver;
    ListNode* heapResult = heapSolver.mergeKLists(listsForStrategy2);
    std::cout << "\nStrategy 2 (Min-Heap / Priority Queue) Output:\n";
    printList(heapResult);

    // Cleanup resources allocations from heap space
    freeList(dcResult);
    freeList(heapResult);

    return 0;
}