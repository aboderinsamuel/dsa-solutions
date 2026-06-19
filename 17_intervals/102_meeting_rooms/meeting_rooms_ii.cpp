#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0, ans = 0;
        int i = 0, j = 0;
        while ( i < n) {
            if (start[i] < end[j]) {
                // new meeting starts before the earliest meeting ends, need new room
                rooms++;
                i++;
            } else {
                // someone left, resue room
                rooms--;
                j++;
            }
            // update answer
            ans = max(ans, rooms);
        }
        return ans;
    }
};