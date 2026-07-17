class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num : nums){
            count[num]++;
        }
        for(auto& entry : count){
            if(entry.second > nums.size() / 2){
                return entry.first;
            }
        }
        return -1;
    }
};