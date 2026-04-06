#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSumSorted(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8};
    int target = 9;
    vector<int> result = twoSumSorted(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found." <<endl;
    }
    return 0;
}