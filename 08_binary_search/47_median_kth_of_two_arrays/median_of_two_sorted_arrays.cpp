#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2;

            int nums1left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1right = (i == m) ? INT_MAX : nums1[i];

            int nums2left = (j == 0) ? INT_MIN : nums2[j-1];
            int nums2right = (j == n) ? INT_MAX : nums2[j];

            if (nums1left <= nums2right && nums2left <= nums1right) {
                if ((m+n) % 2 == 0) {
                    int leftMax = max(nums1left, nums2left);
                    int rightMin = min(nums1right, nums2right);

                    return (leftMax+rightMin) / 2.0;
                }else {
                    return max(nums1left, nums2left);
                }
            }else if (nums1left > nums2right) {
                right = i - 1;
            }else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};
