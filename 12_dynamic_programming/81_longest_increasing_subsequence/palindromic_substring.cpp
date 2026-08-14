class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();

        // dp[i][j] means:
        //
        // "Is the substring from index i to index j
        //  a palindrome?"
        //
        // Example:
        //
        // s = "babad"
        //
        // dp[1][3] asks:
        //
        //     b a b a d
        //       ↑   ↑
        //       1   3
        //
        // Is "aba" a palindrome?
        //
        // Initially, assume every substring is NOT
        // a palindrome.
        vector<vector<bool>> dp(
            n,
            vector<bool>(n, false)
        );


        // This will count EVERY palindrome we discover.
        //
        // Unlike LeetCode 5, we don't need:
        //
        // start
        // maxLen
        //
        // because we're not trying to find the longest one.
        int count = 0;


        // ---------------------------------------------------------
        // Try every possible substring length.
        //
        // Why start at 1?
        //
        // Because even a single character is a palindrome.
        //
        // Example:
        //
        // "abc"
        //
        // "a" → palindrome
        // "b" → palindrome
        // "c" → palindrome
        //
        // So we start with len = 1.
        // ---------------------------------------------------------
        for (int len = 1; len <= n; len++) {


            // -----------------------------------------------------
            // Try every possible starting position.
            //
            // Example:
            //
            // s = "aaa"
            // len = 2
            //
            // i = 0 → "aa"
            // i = 1 → "aa"
            //
            // i = 2 would go outside the string.
            //
            // That's why we use:
            //
            // i + len <= n
            // -----------------------------------------------------
            for (int i = 0; i + len <= n; i++) {


                // -------------------------------------------------
                // Calculate the ending index.
                //
                // If:
                //
                // i = 1
                // len = 3
                //
                // then:
                //
                // j = 1 + 3 - 1
                //   = 3
                //
                // So we're checking:
                //
                // s[1...3]
                // -------------------------------------------------
                int j = i + len - 1;


                // -------------------------------------------------
                // Check whether s[i...j] is a palindrome.
                //
                // TWO things must be true:
                //
                // 1. The first and last characters match.
                //
                //       b a b
                //       ↑   ↑
                //       b == b
                //
                // 2. Either:
                //
                //    - the substring has length 1 or 2
                //
                // OR
                //
                //    - the inside is already a palindrome.
                //
                // Example:
                //
                //       b a b
                //       ↑   ↑
                //
                //       s[i] == s[j]
                //
                //       AND
                //
                //       dp[i+1][j-1]
                //       checks "a"
                //
                // If both conditions are true,
                // the whole substring is a palindrome.
                // -------------------------------------------------
                if (s[i] == s[j] &&
                    (len <= 2 || dp[i + 1][j - 1])) {


                    // -------------------------------------------------
                    // We found a palindrome!
                    //
                    // IMPORTANT:
                    //
                    // We don't just mark it true.
                    //
                    // We also COUNT it.
                    //
                    // This is the major difference from
                    // Longest Palindromic Substring.
                    // -------------------------------------------------
                    dp[i][j] = true;

                    count++;
                }
            }
        }


        // Return the total number of palindromic substrings.
        return count;
    }
};