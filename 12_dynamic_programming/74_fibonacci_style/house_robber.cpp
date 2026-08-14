#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        int prev2 = 0; // best money from two houses back
        int prev1 = 0; // best money from previous house

        for (int money : nums) {

            int current = max(
                prev1,          // DON'T rob this house
                prev2 + money   // ROB this house
            );

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};