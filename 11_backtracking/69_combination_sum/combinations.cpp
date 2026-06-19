#include <vector>
using namespace std;
class Solution {
private:
    void backtrack(int n, int k, int start, vector<int>& current, vector<vector<int>>& result){
        if(current.size() == k){
            result.push_back(current);
            return;
        }
        //Optimization : if not enough elements left, stop
        int remaining = k - current.size();
        int available = n - start + 1;
        if(available < remaining){
            return; //can't form a valid combination
        }
        for(int i=start; i<=n; i++){
            current.push_back(i);
            backtrack(n, k, i+1, current, result);
            current.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }
};