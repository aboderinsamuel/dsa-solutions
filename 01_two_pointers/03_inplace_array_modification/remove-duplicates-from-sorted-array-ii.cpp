class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;
        for(int read = 0; read < nums.size(); ++read){
            if(write < 2 || nums[write - 2] != nums[read]){
                nums[write] = nums[read];
                ++write;
            }
        }
        return write;
    }
};