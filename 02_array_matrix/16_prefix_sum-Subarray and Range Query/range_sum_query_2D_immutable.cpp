#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        //build prefix sums
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                prefix[r+1][c+1] = matrix[r][c] + prefix[r][c+1] + prefix[r+1][c] - prefix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return prefix[row2][col2] - prefix[row1-1][col2] - prefix[row2][col1-1] + prefix[row1-1][col1-1];
    }
};