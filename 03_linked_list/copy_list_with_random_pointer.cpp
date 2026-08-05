#include <unordered_map>
using namespace std;

//Node definition
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> oldToNew;
        // First pass: Create a copy of each node and store the mapping
        Node* curr = head;
        while (curr != nullptr) {
            // Create a new node for each old node and store the mapping
            oldToNew[curr] = new Node(curr->val);
            // Move to the next node
            curr = curr->next;
        }
        // Second pass: Assign next and random pointers for the copied nodes
        curr = head;
        while (curr != nullptr) {
            // Set the next pointer for the copied node
            oldToNew[curr]->next = oldToNew[curr->next];
            // Set the random pointer for the copied node
            oldToNew[curr]->random = (curr->random != nullptr) ? oldToNew[curr->random] : nullptr;
            // Move to the next node
            curr = curr->next;
        }
        // Return the head of the copied list
        return oldToNew[head];
    }
};