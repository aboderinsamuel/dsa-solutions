class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        // dp[i][j] means:
        // "Is the substring from index i to index j a palindrome?"
        //
        // Example:
        // s = "babad"
        //
        // dp[1][3] asks:
        // Is s[1...3] = "aba" a palindrome?
        //
        // We initially assume everything is NOT a palindrome.
        vector<vector<bool>> dp(n, vector<bool>(n, false));


        // We need to remember the BEST palindrome we've found.
        //
        // start  = where the best palindrome begins
        // maxLen = length of the best palindrome
        //
        // We start with maxLen = 1 because every single
        // character is automatically a palindrome.
        int start = 0;
        int maxLen = 1;


        // ---------------------------------------------------------
        // BASE CASE:
        // Every single character is a palindrome.
        //
        // Example:
        //
        // "babad"
        //  ↑
        // "b" is a palindrome
        //
        // "babad"
        //    ↑
        //    "b" is a palindrome
        //
        // Therefore:
        // dp[0][0] = true
        // dp[1][1] = true
        // dp[2][2] = true
        // etc.
        // ---------------------------------------------------------
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }


        // ---------------------------------------------------------
        // NOW CHECK LONGER SUBSTRINGS.
        //
        // len = length of the substring we're currently checking.
        //
        // We start at 2 because we already handled length 1 above.
        //
        // Example:
        //
        // len = 2:
        // "ba", "ab", "ba", "ad"
        //
        // len = 3:
        // "bab", "aba", "bad"
        //
        // len = 4:
        // "baba", "abad"
        //
        // len = 5:
        // "babad"
        //
        // WHY DO WE GO FROM SHORT → LONG?
        //
        // Because a bigger palindrome depends on the smaller
        // palindrome inside it.
        //
        // Example:
        //
        // b a b a b
        // ↑       ↑
        //
        // To know whether "babab" is a palindrome, we need
        // to know whether "aba" (the inside) is a palindrome.
        //
        // So we MUST solve "aba" before "babab".
        // ---------------------------------------------------------
        for (int len = 2; len <= n; len++) {


            // -----------------------------------------------------
            // Try every possible starting position for this length.
            //
            // Example:
            // s = "babad"
            // len = 3
            //
            // i = 0 → "bab"
            // i = 1 → "aba"
            // i = 2 → "bad"
            //
            // We stop before the substring goes outside the array.
            // -----------------------------------------------------
            for (int i = 0; i + len <= n; i++) {


                // -------------------------------------------------
                // Calculate the ending index.
                //
                // i = starting index
                // j = ending index
                //
                // Example:
                //
                // i = 1
                // len = 3
                //
                // indexes:
                //     1 2 3
                //     a b a
                //
                // j = i + len - 1
                //   = 1 + 3 - 1
                //   = 3
                // -------------------------------------------------
                int j = i + len - 1;


                // -------------------------------------------------
                // WHEN IS s[i...j] A PALINDROME?
                //
                // We need TWO things:
                //
                // 1. The first and last characters must match.
                //
                //        b a b
                //        ↑   ↑
                //        b = b
                //
                // 2. The characters INSIDE must also be a palindrome.
                //
                //        b a b
                //          ↑
                //          "a"
                //
                //        b a b a b
                //        ↑       ↑
                //        b       b
                //
                //        inside = "aba"
                //
                // dp[i + 1][j - 1] tells us whether that inside
                // portion is already a palindrome.
                //
                //
                // BUT:
                //
                // What if the substring has only 2 characters?
                //
                // Example:
                //
                // "aa"
                // ↑  ↑
                //
                // If both characters match, "aa" is automatically
                // a palindrome. There is nothing inside to check.
                //
                // That's why we use:
                //
                // len <= 2
                //
                // So:
                //
                // s[i] == s[j]
                //
                // AND
                //
                // (len <= 2 OR dp[i+1][j-1])
                //
                // In plain English:
                //
                // "The outside characters match AND either:
                //
                //  - the substring is only 2 characters long, OR
                //  - the inside is already known to be a palindrome."
                // -------------------------------------------------
                if (s[i] == s[j] &&
                    (len <= 2 || dp[i + 1][j - 1])) {


                    // -------------------------------------------------
                    // We have proven that s[i...j] is a palindrome.
                    //
                    // So record that information.
                    //
                    // Example:
                    //
                    // s = "babad"
                    //
                    // i = 0
                    // j = 2
                    //
                    // "bab" is a palindrome.
                    //
                    // Therefore:
                    //
                    // dp[0][2] = true
                    // -------------------------------------------------
                    dp[i][j] = true;


                    // -------------------------------------------------
                    // We don't just want ANY palindrome.
                    //
                    // We want the LONGEST palindrome.
                    //
                    // So ask:
                    //
                    // Is this palindrome longer than the best
                    // palindrome we've found so far?
                    // -------------------------------------------------
                    if (len > maxLen) {


                        // Remember where this new longest palindrome
                        // starts.
                        //
                        // Example:
                        //
                        // "babad"
                        //  ↑
                        //  start = 0
                        //
                        // If we later find "aba":
                        //
                        // "babad"
                        //   ↑
                        //   start = 1
                        //
                        start = i;


                        // Remember how long the palindrome is.
                        //
                        // Example:
                        //
                        // "bab"
                        // length = 3
                        //
                        // maxLen = 3
                        //
                        maxLen = len;
                    }
                }
            }
        }


        // ---------------------------------------------------------
        // RETURN THE ACTUAL PALINDROME.
        //
        // substr(start, maxLen) means:
        //
        // "Starting at index 'start',
        //  give me 'maxLen' characters."
        //
        // Example:
        //
        // s = "babad"
        //
        // start = 0
        // maxLen = 3
        //
        // s.substr(0, 3)
        //
        // gives:
        //
        // "bab"
        // ---------------------------------------------------------
        return s.substr(start, maxLen);
    }
};