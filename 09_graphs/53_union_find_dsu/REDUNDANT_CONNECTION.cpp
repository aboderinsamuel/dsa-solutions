#include <numeric>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }
    bool unite(int a, int b) {                 // returns false if already joined
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (rank_[ra] < rank_[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rank_[ra] == rank_[rb]) ++rank_[ra];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();          // n nodes, labeled 1..n
        DSU dsu(n + 1);                // +1 because labels are 1-indexed
        for (auto& e : edges) {
            if (!dsu.unite(e[0], e[1]))  // endpoints already connected → cycle
                return e;
        }
        return {};                     // guaranteed unreachable per constraints
    }
};