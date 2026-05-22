#include <iostream>
#include <vector>

// 1. You must explicitly define the custom struct locally
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

// 2. Helper functions to easily build and print lists in your IDE
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

// 3. The main entry point to execute and test the logic
int main() {
    Solution solution;

    // Create test inputs: list1 = [1, 2, 4], list2 = [1, 3, 4]
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});

    std::cout << "Original List 1: ";
    printList(list1);
    std::cout << "Original List 2: ";
    printList(list2);

    // Run the merge algorithm
    ListNode* mergedHead = solution.mergeTwoLists(list1, list2);

    std::cout << "Merged List:    ";
    printList(mergedHead);

    // Clean up heap memory to avoid leaks
    freeList(mergedHead);

    return 0;
}