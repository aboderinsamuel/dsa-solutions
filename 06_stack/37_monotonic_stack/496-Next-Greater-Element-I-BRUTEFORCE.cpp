#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //map each value in nums 2 to its index for O(1) lookups
        unordered_map<int, int> nums2_indexes;
        for (int i=0; i <nums2.size(); ++i) {
            nums2_indexes[nums2[i]] = i;
        }

        vector<int> ans;
        ans.reserve(nums1.size()); //Optimize memory allocation

        //iterate through the subset array
        for (int num : nums1) {
            int start_idx = nums2_indexes[num];
            int next_greater = -1;

            //linearly scan to the right in nums2
            for (int j = start_idx + 1; j < nums2.size(); ++j) {
                if (nums2[j] > num) {
                    next_greater = nums2[j];
                    break;
                }
            }
            ans.push_back(next_greater);
        }
        return ans;
    }
};