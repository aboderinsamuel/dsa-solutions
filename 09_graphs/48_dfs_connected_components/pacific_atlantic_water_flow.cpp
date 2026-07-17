#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col) {
        visited[row][col] = true;
        for (auto [dr, dc] : directions) {
            int newRow = row+dr;
            int newCol = col+dc;
            //outside grid?
            if (newRow < 0 || newRow >= heights.size() || newCol < 0 || newCol >= heights[0].size()) continue;
            //already visited?
            if (visited[newRow][newCol]) continue;
            //height is lower than current cell?
            if (heights[newRow][newCol] < heights[row][col]) continue;
            dfs(heights, visited, newRow, newCol);
            //this means were moving from a cell to a neighbor cell that is higher or equal in height, which is valid for water flow
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        //DFS from Pacific Ocean (top and left edges)
        for (int row = 0; row < cols; row++) dfs(heights, pacific, row, 0); // top edge
        for (int col = 0; col < rows; col++) dfs(heights, pacific, 0,  col); // left edge

        //DFS from Atlantic Ocean (bottom and right edges)
        for (int row = 0; row < cols; row++) dfs(heights, atlantic, row, cols-1); // bottom edge
        for (int col = 0; col < rows; col++) dfs(heights, atlantic, rows-1, col); // right edge

        vector<vector<int>> result;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pacific[row][col] && atlantic[row][col]) {
                    result.push_back({row, col});
                }
            }
        }
        return result;
    }
};