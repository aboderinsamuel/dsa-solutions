//
// Created by USER on 5/22/2026.
//

//Iterative Approach:
#include <vector>
using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr){}
    };

    //solution iterative
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (list1 && list2) {
            //always attach the smaller node to the merged list
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            }else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next; //move the merge list forward
        }
        current->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
class Sol {
public:
    //recursive(uses space stack)
    if (!list1)return list2;
    if (!list2)return list1;

    //choose the node with the smaller value and recurse
    if (list1->val < list2->val) {
        list1->next = mergeTwo(list1->next, list2);
        return list1;
    }else {
        list2->next = mergeTwo(list1, klist2->next);
        return list2;
    }
};