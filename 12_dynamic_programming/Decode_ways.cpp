// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         if(n == 0 || s[0] == '0') return 0;
//
//         vector<int> dp(n+1, 0);
//
//         //empty string
//         dp[0] = 1;
//
//         //first character
//         dp[1] = 1;
//         for(int i=2; i<=n; i++){
//
//             //take 1 digit
//             if(s[i-1] != '0'){
//                 dp[i] += dp[i-1];
//             }
//
//             //take 2 digits
//             int twoDigit = (s[i-2] - '0')* 10  +(s[i-1] - '0');
//             if(twoDigit >= 10 && twoDigit <= 26){
//                 dp[i] += dp[i-2];
//             }
//         }
//         return dp[n];
//     }
// };

#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;

        int prev2 = 1;  //dp[i-2]
        int prev1 = 1; //dp[i-1]


        for(int i=2; i<=n; i++){

            int current = 0;

            //take 1 digit
            if(s[i-1] != '0'){
                current += prev1;
            }

            //take 2 digits
            int twoDigit = (s[i-2] - '0')* 10  +(s[i-1] - '0');
            if(twoDigit >= 10 && twoDigit <= 26){
                current += prev2;
            }
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
