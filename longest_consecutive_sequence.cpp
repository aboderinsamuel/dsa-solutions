#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (seen.count(num - 1)) continue; // skip if not the start of a sequence
            int current = num;
            int length = 1;

            while (seen.count(current+1)) {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};