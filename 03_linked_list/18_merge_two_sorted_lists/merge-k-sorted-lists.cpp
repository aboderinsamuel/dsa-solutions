//
// Created by USER on 5/22/2026.
//
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())return nullptr;

        int k = lists.size();
        while (k>1) {
            for (int i=0; i<k/2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[k-1-i]);
            }
            k = (k+1)/2;
        }
        return lists[0];
    }
};

////////////////////////
////**
* Definition for singly-linked list.
* struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode() : val(0), next(nullptr) {}
    *     ListNode(int x) : val(x), next(nullptr) {}
    *     ListNode(int x, ListNode *next) : val(x), next(next) {}
    * };
*/
class Solution {
public:
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for(ListNode* head : lists){
            if(head != nullptr){
                minHeap.push(head);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if(smallest->next != nullptr){
                minHeap.push(smallest->next);
            }
        }
        return dummy.next;
    }
};