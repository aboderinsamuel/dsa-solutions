#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int, int>>q;
        q.push({0, 0});
        grid[0][0] = 1; // mark as visited and store the distance

        int pathLength = 1;
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},          {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [row, col] = q.front();
                q.pop();

                if (row == n-1 && col == n-1) return pathLength;
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) continue;

                    if(grid[newRow][newCol] == 1) continue;
                    grid[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
            pathLength++;
        }
        return -1;
    }
};