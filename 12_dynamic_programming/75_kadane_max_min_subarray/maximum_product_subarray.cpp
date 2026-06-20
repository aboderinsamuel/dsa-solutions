#include <algorithm>
#include <vector>
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int result = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];

        for(int i=1; i < nums.size(); i++){
            int n = nums[i];

            //compute tempMax first: curMin still needs the OLD curMax
            int tempMax = std::ranges::max({n, curMax*n, curMin*n});
            curMin = std::min({n, curMax*n, curMin*n});
            curMax = tempMax;

            result = std::max(result, curMax);
        }
        return result;
    }
};
