#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>&grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        //the stop conditions
        if (c < 0 || c >= n || r < 0 || r >= m)return;
        if (grid[r][c] != '1')return;

        //mark visited (THIS replaces visited array)
        grid[r][c] = '0';

        //explore neighbors
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};
