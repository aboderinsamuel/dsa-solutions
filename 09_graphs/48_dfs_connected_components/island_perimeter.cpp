class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        //Up, down, left and right
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};

        for(int r=0; r <rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 1){
                    for(int d = 0; d < 4; d++){
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        //off grid or water if this side is exposed
                        if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == 0){
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};