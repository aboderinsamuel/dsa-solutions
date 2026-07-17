class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result[k];
        int a = 0;
        for(int b=0; b<arr.size(); b++){
            if(abs(a-x) < abs(b-x) || abs(a-x) == abs(b-x)){
                result.push_back(a);
            }
        }
    }
};