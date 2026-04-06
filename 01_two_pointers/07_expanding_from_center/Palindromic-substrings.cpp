//
// Created by USER on 4/4/2026.
//

#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += countPalindrome(s, i, i);
            ans += countPalindrome(s, i, i + 1);
        }
        return ans;
    }

    int countPalindrome(const string& ss, int lo, int hi) {
        int ans = 0;
        while (lo >= 0 and hi < ss.size()) {
            if(ss[lo] != ss[hi])break;
            lo--;
            hi++;
            ans++;
        }
        return ans;
    }
};