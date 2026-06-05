//
// Created by samuel on 6/5/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i=0; i<= n - k; ++i)
        {
            unordered_map<int, int> cnt;
            for (int j=i; j < i + k; ++j)
            {
                // note, the key = number, while value = frequency by default
                // because we're using the number itself to search
                ++cnt[nums[j]];
            }
            vector<pair<int, int>> freq;
            for (const auto& [num, count]: cnt)
            {
                freq.emplace_back(count, num);
            }
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());

            int xsum = 0;
            for (int j=0; j < x && j < freq.size(); ++j)
            {
                xsum += freq[j].first * freq[j].second;
            }
            ans.push_back(xsum);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    int x = 17;
    vector<int> ans = sol.findXSum(nums, k, x);
    for (int i=0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
}