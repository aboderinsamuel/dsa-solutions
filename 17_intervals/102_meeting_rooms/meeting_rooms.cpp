#include <vector>
#include <algorithm>

// LC 252 - Meeting Rooms
class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }
        return true;
    }
};
