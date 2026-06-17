#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result){
        //Base case: built a complete permutation
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }
        //try each number, but skip duplicates
        for(int i=0; i<nums.size(); i++){
            //skip if already used
            if(used[i]) continue;

            //skip duplicates
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            //include nums[i]
            current.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, current, used, result);

            //backtrack
            current.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        backtrack(nums, current, used, result);
        return result;
    }
};
