#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> directions = {{0,-1},{0,1},{1,0},{-1,0}};
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return 0;
        if(grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        return 1 + dfs(grid, row-1, col) + dfs(grid, row+1, col) + dfs(grid, row, col-1) + dfs(grid, row, col+1);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int row = 0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(grid[row][col] == 1){
                    int area = dfs(grid, row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

//solution 2:
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row,int col){
        int m = grid.size();
        int n = grid[0].size();

        //stop conditions
        if(r < 0 || c < 0 || r >= m || c >= n) return 0;
        if(grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r, c+1)+ dfs(grid, r, c-1) + dfs(grid, r+1, c) + dfs(grid, r-1, c);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int best = 0;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 1){
                    best = max(best, dfs(grid, r,  c));
                }
            }
        }
        return best;
    }
};