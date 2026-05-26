//
// Created by samuel on 5/26/26.
//
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
    public:
    ListNode* plusOne(ListNode* head)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* notNine = dummy;

        while (head != nullptr)
        {
        if (head->val != 9)
        {
            notNine = head;
        }
        head = head->next;
        }
        notNine->val +=1;

        ListNode* curr = notNine->next;
        while (curr != nullptr)
        {
            curr->val = 0;
            curr = curr->next;
        }
        ListNode* newHead = (dummy->val == 1) ? dummy : dummy->next;
        if (newHead != dummy)delete dummy;
        return newHead;
    }
};