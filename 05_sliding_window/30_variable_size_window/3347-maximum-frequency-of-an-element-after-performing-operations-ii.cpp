// // //Sweep line algorithm for this
// //
// // For any potential target value x, we can count:
// //
// // How many elements are already equal to x (these don't need operations)
// // How many elements can reach x through their range [nums[i] - k, nums[i] + k]
// // The maximum frequency we can achieve for value x is the minimum of:
// //
// // The total number of elements that can reach x (through their ranges)
// // The number of elements already at x plus numOperations (since we can only transform numOperations elements)
// // To efficiently compute this, we use a sweep line technique. For each element nums[i]:
// //
// // It contributes to the "reachability count" for all values in range [nums[i] - k, nums[i] + k]
// // We mark the start of this range with +1 and the end+1 with -1
//
//
// The formula min(s, cnt[x] + numOperations) captures the constraint:
// we can either transform all reachable elements to x (if we have enough operations),
// or we keep the existing cnt[x] elements and use our numOperations to transform additional
// elements.
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        //map to store the frequency of each number in nums
        unordered_map<int, int> frequency;

        //Map to track range boundaries for sweep line algorithm
        //using map (ordered) to process events in sorted order
        map<int, int> rangeBoundaries;

        //process each number in the input array
        for(int num : nums){
            //count frequency of current number
            frequency[num]++;

            //Initialize the number in rangeBoundaries (ensures it exists for later)
            rangeBoundaries[num];

            //mark the start of range where current number can contribute
            //numbers in [num - k, num + k] can be changed to num
            rangeBoundaries[num - k]++;

            //mark end of range (exclusive) here current number stops contributing
            rangeBoundaries[num + k +1 ]--;
        }
        int maxResult = 0;
        int activeCount = 0;

        //sweep through all positions in sorted order
        for(const auto& [position, delta] : rangeBoundaries){
            //update the count of active members that can be changed to current position
            activeCount += delta;

            //calculate the max frequency chaievable at this position:
            // -frequency[position]: numbers already at this position
            // -numOperations: max numbers we can change
            // -activeCount: total numbers available to chnage to this position
            //take minimum of available changes and allowed operations
            maxResult = max(maxResult, min(activeCount, frequency[position] + numOperations));
        }
        return maxResult;
    }
};