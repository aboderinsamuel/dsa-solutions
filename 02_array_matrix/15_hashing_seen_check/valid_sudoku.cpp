#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //store
        unordered_set<string> seen;
        for (int r=0; r<9; r++) {
            for (int c=0; c<9; c++) {
                if (board[r][c] == '.')continue;
                char num = board[r][c];
                int box_index = (r/3)*3 + c/3;

                //build the three unique keys for row, column and box
                string row_key = "row" + to_string(r) + "-" + num;
                string col_key = "col" + to_string(c) + "-" + num;
                string box_key = "box" + to_string(box_index) + "-" + num;

                if (seen.count(row_key) || seen.count(col_key) || seen.count(box_key)) {
                    return false;
                }
                //otherwise add the keys to the set
                seen.insert(row_key);
                seen.insert(col_key);
                seen.insert(box_key);
            }
        }
        return true;
    }
};