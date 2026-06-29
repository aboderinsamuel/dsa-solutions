class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;
        //build the first window
        for(int i=0; i< k; i++){
            windowSum += nums[i];
        }
        int maxSum = windowSum;
        int left = 0;
        //slide window
        for(int right=k; right < nums.size(); right++){
            windowSum += nums[right];
            windowSum -= nums[left];
            left++;

            maxSum = max(maxSum, windowSum);
        }
        return (double)maxSum / k;
    }
};