#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;

        while (read <  chars.size()) {
            char current = chars[read];
            int count = 0;

            while (read < chars.size() && chars[read] == current) {
                read++;
                count++;
            }
            chars[write++] = current;
            if (count  > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};