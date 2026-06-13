#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool isValid(const string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                return isValid(s, left+1, right) || isValid(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};