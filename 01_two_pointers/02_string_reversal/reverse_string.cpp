//
// Created by USER on 3/29/2026.
//
#include<algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    vector<char> s = {'h','e','l','l','o'};
    Solution sol;
    sol.reverseString(s);
    for (char c : s) cout << c << " "; // Output: o l l e h
    return 0;
}