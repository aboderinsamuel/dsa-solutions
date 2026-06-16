#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int current_jump_end = 0;

        for (int i=0; i<nums.size(); i++) {
            farthest = max(farthest, i+nums[i]);
            if (i == current_jump_end) {
                jumps++;
                current_jump_end = farthest;
            }
        }
        return jumps;
    }
};