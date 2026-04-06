class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int i = n - 1; //starting from the last index
        vector<int> result(n);


        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                result[i] = nums[left]*nums[left];
                left++;
            }else{
                result[i] = nums[right]*nums[right];
                right--;
            }
            i--;
        }
        return result;
    }
};