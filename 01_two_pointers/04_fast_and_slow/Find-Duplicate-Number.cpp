//
// Created by USER on 4/2/2026.
//
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    //nums[i is the next pointer
    int slow = nums[0];
    int fast = nums[0];

    //find the intersection point
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while (slow != fast);

    //find entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
};