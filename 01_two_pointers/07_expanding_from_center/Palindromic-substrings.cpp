//
// Created by USER on 4/4/2026.
//

#include <string>
using namespace std;

class Solution {
public:
    int expandAroundCenter(const string& ss, int low, int high){
        int ans = 0;
        while(low >= 0 && high < ss.size() && ss[low] == ss[high]){
            ans++;
            low--;
            high++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); ++i){
            ans += expandAroundCenter(s, i, i);
            ans += expandAroundCenter(s, i, i+1);
        }
        return ans;
    }
};