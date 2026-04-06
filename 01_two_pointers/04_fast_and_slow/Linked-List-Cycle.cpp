#include <iostream>
using namespace std;
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};


// converts vector to linked list automatically
ListNode* buildList(vector<int> nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

int main() {
    // TEST 1 — no cycle
    ListNode* head1 = new ListNode(1);
    head1->next             = new ListNode(2);
    head1->next->next       = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    Solution sol;
    cout << "No cycle: " << sol.hasCycle(head1) << endl;  // 0

    // TEST 2 — with cycle
    ListNode* head2 = new ListNode(1);
    head2->next             = new ListNode(2);
    head2->next->next       = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = head2->next; // cycle here

    cout << "With cycle: " << sol.hasCycle(head2) << endl;  // 1
}
