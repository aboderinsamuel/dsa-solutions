///NB: For union Find: "That's counting connected components in an undirected graph, given as an adjacency matrix."


#include <vector>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> parent, rank_;
    int components;

    explicit DSU(int n) : parent(n), rank_(n, 0), components(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];       // path halving
            x = parent[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB) return false;        // already same province

        if (rank_[rootA] < rank_[rootB]) swap(rootA, rootB);
        parent[rootB] = rootA;                   // shallower under deeper
        if (rank_[rootA] == rank_[rootB]) ++rank_[rootA];

        --components;                            // two provinces became one
        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)      // upper triangle only
                if (isConnected[i][j] == 1)
                    dsu.unite(i, j);

        return dsu.components;
    }
};