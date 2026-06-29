//write code for reverse linked list

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextTemp = current->next; // Store next node
            current->next = prev;               // Reverse the link
            prev = current;                     // Move prev forward
            current = nextTemp;                 // Move current forward
        }
        return prev; // New head of the reversed list
    }
};
