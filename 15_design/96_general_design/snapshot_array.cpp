#include <vector>
using namespace std;

class SnapshotArray {
private:
    vector<vector<pair<int, int>>> data; // Store (snap_id, value) pairs for each index
    int current_snap_id;
public:
    SnapshotArray(int length) {
        data.resize(length);
        current_snap_id = 0;
        // Initialize each index with a default value of 0 at snap_id 0
        for (int i = 0; i < length; ++i) {
            data[i].push_back({0, 0});
        }
    }
    void set(int index, int val) {
        // If the last snap_id is the same as current_snap_id, update the value
        if (data[index].back().first == current_snap_id) {
            data[index].back().second = val;
        } else {
            // Otherwise, add a new entry for the current snap_id
            data[index].push_back({current_snap_id, val});
        }
    }
    int snap() {
        return current_snap_id++;
    }
    int get(int index, int snap_id) {
        // Binary search to find the value at the given snap_id
        const auto& entries = data[index];
        int left = 0, right = entries.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (entries[mid].first <= snap_id) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // The right pointer will be at the largest snap_id <= requested snap_id
        return entries[right].second;
    }
};