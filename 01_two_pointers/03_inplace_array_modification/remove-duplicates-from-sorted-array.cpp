//
// Created by USER on 3/30/2026.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 1;
        for (int read = 1; read < nums.size(); ++read) {
            if (nums[read] != nums[read - 1]) {
                nums[write] = nums[read];
                ++write;
            }
        }
        return write;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int results = sol.removeDuplicates(nums);
    cout << results << endl;
}