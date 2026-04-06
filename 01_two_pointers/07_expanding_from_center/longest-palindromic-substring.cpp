//
// Created by USER on 4/4/2026.
//
#include <string>
using namespace std;

// Helper function to expand around a center and return the length of the palindrome
int expandAroundCenter(const string& s, int left, int right) {
    // Expand as long as the characters match and indices are within bounds
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;   // Move left pointer outward
        right++;  // Move right pointer outward
    }
    // Return the length of the palindrome found
    return right - left - 1; // Subtract 1 because the last increment/decrement went too far
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0;  // Start index of the longest palindrome found
    int maxLen = 1; // Length of the longest palindrome

    for (int center = 0; center < s.length(); ++center) {
        // Odd-length palindrome (centered at one character)
        int len1 = expandAroundCenter(s, center, center);
        // Even-length palindrome (centered between two characters)
        int len2 = expandAroundCenter(s, center, center + 1);

        int currLen = max(len1, len2);

        // If we found a longer palindrome, update start and maxLen
        if (currLen > maxLen) {
            maxLen = currLen;
            // Calculate new start index based on current center and length
            start = center - (currLen - 1) / 2;
        }
    }
    // Return the longest palindromic substring
    return s.substr(start, maxLen);
}