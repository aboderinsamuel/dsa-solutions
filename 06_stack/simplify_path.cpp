#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string current = "";

        for (int i=0; i<path.size(); i++) {
            char c = path[i];
            if (c == '/') {
                //process accumulated curent string
                if (current == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                current = "";
            } else {
                current += c;
            }
        }
        //process the last component
        if (current == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (!current.empty() && current != ".") {
            st.push(current);
        }
        //build  result
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};