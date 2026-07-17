#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };
    void wallsandGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        int rows = rooms.size();
        int cols = rooms[0].size();

        queue<pair<int, int>> q;
        for (int row=0; row<rows; row++) {
            for (int col=0; col<cols; col++) {
                if (rooms[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
                    continue;
                }
                if (rooms[newRow][newCol] != INT_MAX) {
                    rooms[newRow][newCol] = rooms[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};