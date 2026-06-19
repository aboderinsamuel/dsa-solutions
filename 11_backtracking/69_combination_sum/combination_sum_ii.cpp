#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& current, vector<vector<int>>& result){
        //Base case: target reached
        if(target == 0){
            result.push_back(current);
            return;
        }
        //try each candidate from idx downwards
        for(int i=idx; i < candidates.size(); i++){
            //Early termination
            if(candidates[i] > target){
                break;
            }
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            //Include candidates[i]
            current.push_back(candidates[i]);

            //recurse
            backtrack(candidates, target-candidates[i], i+1, current, result);

            //backtrack
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};