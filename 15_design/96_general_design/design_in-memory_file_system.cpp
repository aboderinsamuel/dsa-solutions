#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class FileSystem {
private:
    struct Node {
        string name;
        bool isFile;
        string content;
        unordered_map<string, Node*> children;
        Node(string name) {
            this->name = name;
            isFile = false;
        }
    };

    Node* root;
    vector<string> split(string path) {
        vector<string> parts;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            if (token != "") {
                parts.push_back(token);
            }
        }
        return parts;
    }

};
