//
// Created by USER on 3/29/2026.
//
#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int write = 0;
        long long totalSwaps = 0;

        for(int read = 0; read < s.length(); ++read){
            if(s[read] == '0'){
                totalSwaps += read - write;
                ++write;
            }
        }
        return totalSwaps;
    }
};