#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while (start < end) {
            if (start < end && !isalnum(s[start])) {
                start++;
            }else if (start < end && !isalnum(s[end])) {
                end--;
            }else if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }else {
                start++;
                end--;
            }
        }
        return true;
    }
};