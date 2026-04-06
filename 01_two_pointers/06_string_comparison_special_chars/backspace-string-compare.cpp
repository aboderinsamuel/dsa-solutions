//
// Created by USER on 4/3/2026.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int getNextValidCharIndex(const string& str, int index) {
        int backspaceCount = 0;
        while (index >= 0) {
            if (str[index] == '#') {
                backspaceCount++;
            }else if (backspaceCount > 0) {
                backspaceCount--;
            }else {
                break;
            }
            index--;
        }
        return index;
    }
    bool backspaceCompare(string s, string t) {
            int i = s.length() - 1;
            int j = t.length() - 1;


            while (i >= 0 || j >= 0) {
                i = getNextValidCharIndex(s, i);
                j = getNextValidCharIndex(t, j);

                if (i < 0 && j < 0)return true;
                if (i < 0 || j < 0)return false;
                if (s[i] != t[j])return false;

                i--;
                j--;
            }
            return true;
        }
};
