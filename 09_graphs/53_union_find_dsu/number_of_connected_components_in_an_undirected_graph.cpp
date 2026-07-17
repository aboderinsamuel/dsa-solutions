#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        //Each node is its own parent initially
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        //find path with compression
        function<int(int)> find = [&](int x) -> int {
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        //Union by rank
        auto unite = [&](int x, int y){
            int rootX = find(x);
            int rootY = find(y);

            if(rootX == rootY) return;
            if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            }else if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        };
        //process all edges
        for(auto& edge : edges){
            unite(edge[0], edge[1]);
        }
        //count unique roots
        int components = 0;
        for(int i=0; i<n; i++){
            if(find(i) == i){
                components++;
            }
        }
        return components;
    }
};