#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& current, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(current);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            //Early termination : if sorted, can break early
            if(candidates[i] > target){
                break;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i, current, result);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};