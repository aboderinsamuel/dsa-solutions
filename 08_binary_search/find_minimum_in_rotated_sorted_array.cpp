#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // 🧒 We shrink the window until left and right point at the SAME
        // index. Whatever's left at that point is the answer, so we use
        // strict "<" here, not "<=" like in a normal binary search where
        // you're still checking a range with more than one candidate.
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 🧒 THE KEY QUESTION: compare the middle element to the
            // RIGHTMOST element, not the leftmost. Picture the array as
            // two sorted "hills." If nums[mid] is bigger than nums[right],
            // that means the array "dropped" somewhere between mid and
            // right, so the low point (the minimum) has to be hiding
            // there, strictly after mid.
            if (nums[mid] > nums[right]) {
                left = mid + 1; // safe to throw mid away, it can't be the min
            } else {
                // 🧒 If nums[mid] <= nums[right], then mid all the way to
                // right is already sorted normally (no drop in that
                // stretch). So the minimum is either mid itself or
                // somewhere to its left. We keep mid IN the range
                // (not mid - 1) because mid could genuinely be the answer.
                right = mid;
            }
        }

        // left and right have converged onto one index: the minimum.
        return nums[left];
    }
};