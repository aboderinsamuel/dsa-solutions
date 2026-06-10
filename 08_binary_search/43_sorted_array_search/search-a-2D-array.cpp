class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //row = mid / cols
        //col = mid % cols

        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows*cols - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            int row = mid / cols;
            int col = mid % cols;

            int val = matrix[row][col];

            if(val == target){
                return true;
            }
            else if(val < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
};