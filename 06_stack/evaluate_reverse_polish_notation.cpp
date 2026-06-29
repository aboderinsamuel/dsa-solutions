#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalPIN(vector<string>& tokens) {
        stack<int> st;
        for (string& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                st.push(stoi(token));
            }else{
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                switch (token[0]) {
                    case '+' : st.push(a + b); break;
                    case '-' : st.push(a - b); break;
                    case '*' : st.push(a * b); break;
                    case '/' : st.push(a / b); break;
                }
            }
        }
        return st.top();
    }
};