//
// Created by samuel on 6/5/26.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int streak = 1; //To Track consecutive elements
        vector<int> ans;
        int n = nums.size();

        //edge case: if K is 1, every single element is its own valid subarray.
        if(k == 1){
            return nums;
        }

        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i - 1] + 1){
                streak++;
            }else{
                streak = 1;
            }

            //once our window is big enough to start recording answers...
            if(i >=k -1){
                if(streak >= k){
                    ans.push_back(nums[i]); //max is the current number when this happens
                }else{
                    ans.push_back(-1); //Invalid window
                }
            }
        }
        return ans;
    }
};