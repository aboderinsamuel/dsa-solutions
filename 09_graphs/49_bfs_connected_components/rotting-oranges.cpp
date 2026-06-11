#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangeRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        //queue for bfs
        queue<pair<int, int>> q;
        int freshCount = 0;

        //put all rotten oranges into queue
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                //rotten orange found
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        //no fresh orange found, then no stress
        if (freshCount == 0) {
            return 0;
        }

        // BFS PREP
        int minutes = 0;
        vector<pair<int, int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        //BFS Start
        while (!q.empty()) {
            int levelSize = q.size();
            bool rottedSomething = false;

            //process entire current level
            for (int i=0; i<levelSize; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int newRow = r + dir.first;
                    int newCol = c + dir.second;

                    if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                        continue;
                    }

                    if (grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshCount--;
                        q.push({newRow, newCol});
                        rottedSomething = true;
                    }
                }
            }
            if (rottedSomething) {
                minutes++;
            }
        }
        if (freshCount > 0) {
            return -1;
        }
        return minutes;
    }
};