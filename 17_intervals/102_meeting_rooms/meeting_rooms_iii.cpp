#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <ranges>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Array to count how many meetings each room has hosted
        vector<int> meeting_count(n, 0);

        // Sort the meetings chronologically by their start times
        ranges::sort(meetings);

        // Min-heap for occupied rooms storing pairs of {end_time, room_number}
        // Ordered by earliest end time first; tie-broken by smallest room number
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupied_rooms;

        // Min-heap for available room indices, keeping the lowest-numbered room on top
        priority_queue<int, vector<int>, greater<>> available_rooms;

        // Initially, all rooms from 0 to n-1 are available
        for (int i = 0; i < n; ++i) {
            available_rooms.push(i);
        }

        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Free up rooms whose meetings end at or before the current meeting's start time
            while (!occupied_rooms.empty() && occupied_rooms.top().first <= start) {
                int freed_room = occupied_rooms.top().second;
                occupied_rooms.pop();
                available_rooms.push(freed_room);
            }

            // Case 1: There is an available room (always pick the one with the smallest index)
            if (!available_rooms.empty()) {
                int room = available_rooms.top();
                available_rooms.pop();

                meeting_count[room]++;
                occupied_rooms.push({end, room});
            }
            // Case 2: No rooms are available. Delay the meeting to the earliest available room's end time.
            else {
                auto [earliest_end_time, room] = occupied_rooms.top();
                occupied_rooms.pop();

                // Calculate new end time while preserving the original duration (end - start)
                long long duration = end - start;
                meeting_count[room]++;

                occupied_rooms.push({earliest_end_time + duration, room});
            }
        }

        // Find the room with the maximum number of meetings
        int max_meetings = -1;
        int best_room = -1;

        for (int i = 0; i < n; ++i) {
            if (meeting_count[i] > max_meetings) {
                max_meetings = meeting_count[i];
                best_room = i;
            }
        }
        return best_room;
    }
};