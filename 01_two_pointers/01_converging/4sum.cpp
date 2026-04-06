//
// Created by USER on 3/29/2026.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for(int i= 0; i < n - 3; ++i){
            if(i > 0 && nums[i] == nums[i - 1])continue; //skip duplicates in array
            for(int j = i + 1; j < n - 2; ++j){
                if(j > i + 1 && nums[j] == nums[j - 1])continue;
                int left = j + 1;
                int right = n - 1;

                while(left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1])left++;
                        while(left < right && nums[right] == nums[right - 1])right--;
                        left++;
                        right--;
                    }else if(sum < target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> myNums = {1,2,3,4,5,1,-11,9,3,4,2,1,2,7,77};
    int myTarget = 9;

    Solution mySolution;
    vector<vector<int>> ans = mySolution.fourSum(myNums, myTarget);

    for (const auto& quad : ans) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
};