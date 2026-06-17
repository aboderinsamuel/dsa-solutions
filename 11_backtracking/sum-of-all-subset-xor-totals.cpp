#include <vector>
using namespace std;
class Solution {
private:
    int totalXOR = 0;
    void backtrack(vector<int>& nums, int idx, int currentXOR) {
        if (idx == nums.size()) {
            totalXOR += currentXOR;
            return;
        }
        // Include the current number in the subset
        backtrack(nums, idx + 1, currentXOR ^ nums[idx]);
        // Exclude the current number from the subset
        backtrack(nums, idx + 1, currentXOR);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return totalXOR;
    }
};