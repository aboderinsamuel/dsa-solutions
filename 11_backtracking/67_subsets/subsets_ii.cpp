#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, int idx, std::vector<int>& current, std::vector<std::vector<int>>& result){
        //add current subset to result;
        result.push_back(current);
        //try including elements from idx downwards
        for(int i=idx; i<nums.size(); i++){
            //skip duplicate: if current element equals previous at same level
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            //include nums[i]
            current.push_back(nums[i]);
            backtrack(nums, i+1, current, result);
            current.pop_back(); //backtrack 
        }
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); //CRITICAL
        std::vector<int> current;
        std::vector<std::vector<int>> result;
        backtrack(nums, 0, current, result);
        return result;
    }
};