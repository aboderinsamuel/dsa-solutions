#include <vector>
#include <unordered_map>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    unordered_map<Node*, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        //if already cloned, return the clone
        if (cloned.count(node)) {
            return cloned[node];
        }
        //clone the node
        Node* copy = new Node(node->val);
        cloned[node] = copy;
        //clone the neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }
        return copy;
    }
};