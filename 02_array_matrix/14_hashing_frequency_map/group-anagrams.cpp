#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

/* * Time: O(N * K log K) | Why: We loop N times, and sorting each string takes K log K.
 * Space: O(N * K)      | Why: The map and result array store all N strings of length K.
 */

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& groups : mp) {
            result.push_back(groups.second);
        }
        return result;
    }
};
