//
// Created by samuel on 6/5/26.
//
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> seen;
        for (int i=0; i < nums.size(); ++i)
        {
            int currentNum = nums[i];
            if (seen.count(currentNum) && i - seen[currentNum] <= k)
            {
                return true;
            }
            seen[currentNum] = i;
        }
        return false;
    }
};