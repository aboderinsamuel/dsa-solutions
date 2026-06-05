//
// Created by samuel on 6/5/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minSubArrayLen(int target, const vector<int>& nums)
{
    int minLength = INT_MAX;
    int windowSum = 0;
    int windowStart = 0;

    for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
    {
        windowSum += nums[windowEnd];
        //while condition is met, try to shrink window from the left
        while (windowSum >= target)
        {
            minLength = min(minLength, windowEnd - windowStart + 1);
            windowSum -= nums[windowStart];
            windowStart++;
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}

int main()
{
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    cout << "Min Length: " << minSubArrayLen(7, arr) << endl;
    return 0;
}