#include <vector>

//add listnode strct for question, reverse linked list leetcode II:

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* beforeLeft = &dummy;
        for (int i = 1; i < left; ++i) {
            beforeLeft = beforeLeft->next;
        }
        ListNode* prev = nullptr;
        ListNode* current = beforeLeft->next;
        ListNode* leftNode = current; // This will be the new tail after reversal

        for (int i = left; i <= right; ++i) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        beforeLeft->next = prev; // Connect the node before left to the new head of reversed sublist
        leftNode->next = current; // Connect the new tail of reversed sublist to the node after right
        return dummy.next; // Return the new head of the list

    }
};