/*
## Problem Statement: Largest Palindromic Number

You are given a string `S` consisting only of numerical digits (`'0'` through `'9'`).
Your task is to construct the **largest possible palindromic integer** (represented as a string)
by using a subset (or all) of the digits present in `S`.

A palindrome is defined as a sequence of characters that reads the same forwards and backwards.

---

### Key Points & Rules

1. **Use Available Digits:** You must use at least one digit from string `S`.
2. **Free Reordering:** You may rearrange and reorder the chosen digits freely.
3. **No Leading Zeros:** The resulting palindromic number must **not** contain leading zeros,
except when the entire number itself is `"0"`.
4. **Maximize Value:** You must return the **largest possible** palindromic number that can be formed.
5. **Zero-Only Edge Case:** When only `'0'` digits exist (or no non-zero digits can form a valid non-zero number),
the result must be `"0"`.

---

### Assumptions & Constraints

* **Length of String:** $N$ is an integer within the range $[1 \dots 100,000]$.
* **Content:** String $S$ is made up entirely of decimal digits (`'0'` – `'9'`).
* **Efficiency:** The solution must run in optimal $\mathcal{O}(N)$ time complexity to efficiently
* handle inputs up to $100,000$ characters.
*/




#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string &S) {
    int N = S.length(); // Explicitly captures N from range [1..100,000]
    vector<int> count(10, 0);
    
    for (int i = 0; i < N; ++i) {
        count[S[i] - '0']++;
    }

    string left = "";

    // Build outer pairs using digits 9 down to 1
    for (int d = 9; d >= 1; --d) {
        int pairs = count[d] / 2;
        left.append(pairs, '0' + d);
        count[d] %= 2;
    }

    // Include zero pairs only if we have higher non-zero leading digits
    if (!left.empty()) {
        int zero_pairs = count[0] / 2;
        left.append(zero_pairs, '0');
        count[0] %= 2;
    }

    // Pick largest single remaining digit for the center
    string mid = "";
    for (int d = 9; d >= 0; --d) {
        if (count[d] > 0) {
            mid = string(1, '0' + d);
            break;
        }
    }

    // If no pairs exist, return the largest single available digit ("0" if only zeros exist)
    if (left.empty()) {
        return mid.empty() ? "0" : mid;
    }

    // Assemble palindrome: left + mid + reverse(left)
    string right = left;
    reverse(right.begin(), right.end());

    return left + mid + right;
}