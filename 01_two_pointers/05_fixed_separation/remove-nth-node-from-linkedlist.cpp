/**
* Definition for singly-linked list.
**/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //create a dummy node to simplify edge cases (like removing the head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        //initialize two pointers, both start at dummy
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        //move fast poiner n + 1 steps ahead so that slow will point to the node before the one to remove
        for(int i = 0; i <= n; ++i){
            //Always check for nullptr to avoid crash
            if(fast) fast = fast->next;
        }

        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next; //remove node;

        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;

    }
};
//
// Created by USER on 4/3/2026.
//