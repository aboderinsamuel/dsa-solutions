//
// Created by USER on 3/29/2026.
//
// Problem: Reverse Vowels of a String
// Reverse only the vowels in the string.

#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

string reverseVowels(string s) {
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Move left pointer forward until it points to a vowel
        while (left < right && vowels.find(s[left]) == vowels.end()) left++;
        // Move right pointer backward until it points to a vowel
        while (left < right && vowels.find(s[right]) == vowels.end()) right--;
        // Swap the vowels
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

// Usage Example
int main() {
    string s = "IceCreAm";
    cout << reverseVowels(s) << endl; // Output: "AmCeCrIe"
    return 0;
}
