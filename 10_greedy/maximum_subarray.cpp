//use our method + kandane's theorem
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int runningSum = 0;
        int maxSum = nums[0];

        for (int x : nums) {
            if (runningSum < 0) {
                runningSum = x;
            }else {
                runningSum += x;
            }
            maxSum = max(maxSum, runningSum);
        }
        return maxSum;
    }
};