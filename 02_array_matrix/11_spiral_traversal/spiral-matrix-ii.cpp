
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int num = 1;

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int col=left; col<=right; ++col) {
                matrix[top][col] = num++;
            }
            top++;

            for (int row=top; row <= bottom; ++row) {
                matrix[row][right] = num++;
            }
            right--;

            if (top <= bottom) {
                for (int col=right; col>=left; --col) {
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int row=bottom; row>=top; --row) {
                    matrix[row][left] = num++;
                }
                left++;
            }
        }
        return matrix;
    }
};