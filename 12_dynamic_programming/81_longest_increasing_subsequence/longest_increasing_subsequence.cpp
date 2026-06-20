//There are two ways to do this, binray search which is optimal and dp sub-optimal
//space : O(n log n) , time : O(n) -- binary seach
//space : O(n^2) , time : O(n^2) -- dp

#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for(int num  :nums){
            auto it = lower_bound(tails.begin(), tails.end(), num);

            //replace it
            if(it == tails.end()){
                tails.push_back(num);
            }
            else{
                *it = num;
            }
        }
        return tails.size();
    }
};
class secondSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};