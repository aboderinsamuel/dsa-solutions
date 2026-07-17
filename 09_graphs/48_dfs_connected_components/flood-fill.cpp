#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor){
        //Outside the grid
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size()) return;
        //different color?
        if(image[row][col] != oldColor) return;
        //paint this cell
        image[row][col] = newColor;
        for(auto [dr,dc] : directions){
            dfs(image, row+dr, col+dc, oldColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        dfs(image, sr, sc, oldColor, color);
        return image;

    }
};