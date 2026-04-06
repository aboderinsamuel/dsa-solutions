//
// Created by USER on 4/2/2026.
//
int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while (slow != fast);

    slow = nums[slow];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
};