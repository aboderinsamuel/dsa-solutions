//
// Created by USER on 4/30/2026.
//
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int write = 0;

        for (int read=0; read < s.length(); ++read) {
            if (s[read] == '*') {
                write--;
            }else {
                s[write] = s[read];
                write++;
            }
        }
        return s.substr(0, write);
    }
};



