#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxCount = 0;
        vector<int> count(26, 0);
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);


            while ((right-left  +1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};