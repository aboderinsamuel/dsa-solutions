#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemps(vector<int>& temps) {
        stack<int> myStack;
        int n =temps.size();
        vector<int> result(n);

        for (int i=n-1; i>=0; --i) {
            while (!myStack.empty() && temps[myStack.top()] <= temps[i]) {
                myStack.pop();
            }
            if (!myStack.empty()) {
                result[i] = myStack.top() - i;
            }
            myStack.push(i);
        }
        return result;
    }
};