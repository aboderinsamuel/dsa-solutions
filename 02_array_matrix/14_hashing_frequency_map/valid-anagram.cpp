// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length())return false;
//
//         vector<int> count(26, 0);
//         for(int i=0; i<s.length(); i++){
//             count[s[i]- 'a']++;
//             count[t[i] - 'a']--;
//         }
//         for(int c : count){
//             if(c != 0 )return false;
//         }
//         return true;
//     }
// };

/* * Time: O(N)  | Why: We iterate through the strings of length N exactly once.
 * Space: O(1) | Why: The frequency array is always exactly size 26, which is constant.
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> count(26, 0);
        for (int i=0; i<t.length(); i++) {
            count[t[i] - 'a']++;
            count[s[i] - 'a']--;
        }

        for (int c : count) {
            if (c != 0) return false;
        }
        return true;
    }
};

