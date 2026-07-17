#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = right;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        //copy the remaining elements from the left half
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        //copy the remaining elements from the right half
        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }
        //copy the sorted elements back to the original array
        for (int k=0; k<temp.size(); k++) {
            nums[left+k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        //find the middle index
        int mid = left + (right - left) / 2;
        //sort the left half
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        //merge the two halves
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};