#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int rows, cols;
    bool dfs(int r, int c, int index, const vector<vector<char>>& board, const string& word){
        if(index == word.length()){
            return true;
        }
        //check if cell is out of bounds or doesnt match current character
        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[index]){
            return false;
        }
        //temprarily mark the current cell as visited by changing its character, (so we don't reuse the same cell in the current path)
        char temp = board[r][c];
        const_cast<vector<vector<char>>&>(board)[r][c] = '#';

        //Explore all 4 cardinal directions: Up, DOWN, LEFT, RIGHT
        bool found = dfs(r+1, c, index+1, board, word) || dfs(r-1, c, index+1, board, word) || dfs(r, c+1, index+1, board, word) || dfs(r, c-1, index+1, board, word);

        //Backtrack: Restore the original character of the cell for future searches/paths
        const_cast<vector<vector<char>>&>(board)[r][c] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int r=0; r < rows; ++r){
            for(int c=0; c < cols; ++c){
                //If the starting character matches, begin the DFS traversal
                if(board[r][c] == word[0] && dfs(r, c, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};