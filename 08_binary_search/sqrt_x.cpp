class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int left = 1;
        int right = x;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mid == x/mid){
                return mid; //perfect square
            }else if(mid < x/mid){
                left = mid+1; //sqrt is larger
            }else{
                right = mid -1; //sqrt is smaller
            }
        }
        return right; //right is the floor of sqrt(x)
    }
};