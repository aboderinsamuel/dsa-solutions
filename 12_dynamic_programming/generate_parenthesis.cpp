#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
            // this means we have a valid combination of parentheses
            // 2*n means we have used all the parentheses
        }
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
};