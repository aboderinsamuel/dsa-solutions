#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col >= grid[0].size() || col < 0) return;
        if(grid[row][col] == '0') return;
        grid[row][col] = '0';
        for(auto [dr, dc] : directions){
            dfs(grid, row+dr, col+dc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(grid[row][col] == '1'){
                    islands++;
                    dfs(grid, row, col);
                }
            }
        }
        return islands;
    }
};
