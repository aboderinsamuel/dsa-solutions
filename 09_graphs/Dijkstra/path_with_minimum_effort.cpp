#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // {effort, row, col}
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currentEffort = current[0];
            int row = current[1];
            int col = current[2];

            //Ignore if we have already found a better path to this cell
            if (currentEffort > effort[row][col]) continue;
            //reached destination
            if (row == rows - 1 && col == cols - 1) return currentEffort;
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;

                //Calculate the effort to reach the neighbor
                int jump = abs(heights[row][col] - heights[newRow][newCol]);
                //largest jump so far
                int newEffort = max(currentEffort, jump);
                if (newEffort < effort[newRow][newCol]) {
                    effort[newRow][newCol] = newEffort;
                    pq.push({newEffort, newRow, newCol});
                }
            }
        }
        return 0;
    }
};