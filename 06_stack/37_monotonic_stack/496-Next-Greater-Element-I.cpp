#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Stack to maintain elements in decreasing order
        stack<int> monotonicStack;

        // Map to store the next greater element for each number
        unordered_map<int, int> nextGreaterMap;

        // Reverse nums2 to process from right to left
        reverse(nums2.begin(), nums2.end());

        // Process each element in nums2 from right to left (after reversal)
        for (int currentNum : nums2) {
            // Pop elements from stack that are smaller than current number
            // These elements cannot be the next greater for any future elements
            while (!monotonicStack.empty() && monotonicStack.top() < currentNum) {
                monotonicStack.pop();
            }

            // If stack is not empty, the top element is the next greater element
            if (!monotonicStack.empty()) {
                nextGreaterMap[currentNum] = monotonicStack.top();
            }

            // Push current element to stack for future comparisons
            monotonicStack.push(currentNum);
        }

        // Build result array based on nums1
        vector<int> result;
        for (int num : nums1) {
            // Check if next greater element exists in map, otherwise use -1
            if (nextGreaterMap.find(num) != nextGreaterMap.end()) {
                result.push_back(nextGreaterMap[num]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};