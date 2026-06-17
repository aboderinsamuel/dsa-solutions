#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& result){
        //base case: reached end, add current permutation
        if(idx == nums.size()){
            result.push_back(nums);
            return;
        }
        //Try swapping nums[idx] with every element from idx onwards
        for(int i=idx; i < nums.size(); i++){
            //swap
            swap(nums[idx], nums[i]);

            //recurse with next position fixed
            backtrack(nums, idx+1, result);

            //backtrack : undo swap
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};