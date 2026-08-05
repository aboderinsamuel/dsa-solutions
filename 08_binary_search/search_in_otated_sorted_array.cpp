class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // found it, done
            }

            // 🧒 STEP 1: figure out which HALF is the normal, unbroken,
            // sorted one. Compare mid to left, not to right this time —
            // either way works, just be consistent about it.
            if (nums[left] <= nums[mid]) {
                // Left half [left..mid] is sorted normally (no rotation
                // break in this stretch).

                // 🧒 STEP 2: is target actually inside that sorted
                // stretch's range? If yes, search there. If no, the
                // target MUST be somewhere in the other half instead.
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // Otherwise, the RIGHT half [mid..right] must be the
                // sorted one instead (the break happened on the left side).
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1; // target never found
    }
};