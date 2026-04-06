//
// Created by USER on 4/3/2026.
//
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slow = 0;
        int fast = 0;

        while(slow < s.size() && fast < t.size()){
            if(s[slow] == t[fast])slow++;
            fast++;
        }
        return slow == s.size();
    }
};