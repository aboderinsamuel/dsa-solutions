#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        for (int i=0; i<s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }
        vector<int> result;
        int farthest = 0;
        int start = 0;
        for (int i=0; i<s.size(); ++i) {
            farthest = max(farthest, last[s[i] - 'a']);

            if (i == farthest) {
                result.push_back( i - start+1);
                start = i + 1;
            }
        }
        return result;
    }
};