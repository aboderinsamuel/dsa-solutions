class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;

        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(mat[r][c] == 0) q.push({r, c});
                else mat[r][c] = -1; //-1 = unvisited
            }
        }

        static constexpr int dr[4] = {-1, 1, 0, 0};
        static constexpr int dc[4] = {0, 0, -1, 1};

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [r, c] = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if(mat[nr][nc] != -1) continue;
                    mat[nr][nc] = level + 1;
                    q.push({nr, nc});
                }
            }
            level++;
        }
        return mat;
    }
};