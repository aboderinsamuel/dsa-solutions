#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& result) {
        //Base case: weve considered all elements
        if (idx == nums.size()) {
            result.push_back(current);
            return;
        }
        //Include the current element
        current.push_back(nums[idx]);
        backtrack(nums, idx + 1, current, result);
        //Exclude the current element
        current.pop_back();
        backtrack(nums, idx + 1, current, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};