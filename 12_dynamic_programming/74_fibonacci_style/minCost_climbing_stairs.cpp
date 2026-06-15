#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int prev2 = 0;
        int prev1 = 0;

        for(int i=2; i<=n; ++i){
            int takeOneStep = prev1 + cost[i-1];
            int takeTwoSteps = prev2 + cost[i-2];

            int current = min(takeOneStep, takeTwoSteps);

            //shift the sliding window forward
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};