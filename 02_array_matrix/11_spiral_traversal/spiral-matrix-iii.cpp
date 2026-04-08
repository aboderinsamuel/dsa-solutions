#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = rows * cols;
        int r = rStart, c = cStart;
        int len = 1;
        // directions: east, south, west, north
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int d = 0;

        result.push_back({r, c});

        while (result.size() < total) {
            for (int turn = 0; turn < 2; ++turn) {
                for (int i = 0; i < len; ++i) {
                    r += dr[d];
                    c += dc[d];
                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                        result.push_back({r, c});
                }
                d = (d + 1) % 4;
            }
            len++;
        }
        return result;
    }
};