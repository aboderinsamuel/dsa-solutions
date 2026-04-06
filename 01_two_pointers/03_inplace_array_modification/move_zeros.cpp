//
// Created by USER on 3/29/2026.
//
// Problem: Move Zeroes
// Goal: Move all 0's to the end, maintain order of non-zero elements, in-place

#include <vector>
#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int write = 0; // Position to place the next non-zero element

    // Step 1: Move all non-zero elements to the front
    for (int read = 0; read < nums.size(); ++read) {
        if (nums[read] != 0) {
            nums[write] = nums[read]; // Place non-zero at write position
            ++write; // Move write pointer forward
        }
    }

    // Step 2: Fill the rest with zeros
    while (write < nums.size()) {
        nums[write] = 0;
        ++write;
    }
}

// Usage example:
int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    // Output the modified array
    for (int n : nums) cout << n << " "; // 1 3 12 0 0
    return 0;
}