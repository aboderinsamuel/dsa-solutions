#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // dp[i][j] = LPS length in s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every single character is a palindrome of length 1
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill by increasing substring length
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if(s[i] == s[j]) {
                    // Characters match → include both ends
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    // Characters don't match → skip one end
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};
