#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int originalColor,  int newColor){
        int rows = image.size();
        int cols = image[0].size();

        //case1: out of bounds
        if(row < 0 || row >= rows || col < 0 || col >= cols){
            return;
        }
        //case2: wrong color
        if(image[row][col] != originalColor){
            return;
        }
        //paint current cell
        image[row][col] = newColor;
        //explore 4 directions
        dfs(image, row+1, col, originalColor, newColor); //Down
        dfs(image, row-1, col, originalColor, newColor); //Up
        dfs(image, row, col+1, originalColor, newColor); //right
        dfs(image, row, col-1, originalColor, newColor); //left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color){
            return image;
        }
        //dfs from the starting pixel
        dfs(image, sr, sc, originalColor, color);
        //return modified image
        return image;
    }
};