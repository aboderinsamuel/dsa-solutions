#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //A tree ust have exactly n-1 edges
        if (edges.size() != n-1) return false; return false;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        //Each node is its own parent initially
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        //find path with compression
        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        //union by rank
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) return false; //cycle detected
            if (rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        };
        //process all edges
        for (auto& edge : edges){
            if (!unite(edge[0], edge[1])) {
                return false; //cycle detected
            }
        }
        return true; //no cycles and n-1 edges means it's a valid tree
    }
};
