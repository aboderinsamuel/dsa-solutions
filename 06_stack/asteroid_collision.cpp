class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int asteroid : asteroids){
            bool alive = true;
            while(alive && asteroid < 0 && !st.empty() && st.top() > 0){
                //collision: right-moving top vs left-moving current
                int right = st.top();
                if(right < abs(asteroid)){
                    //leftmoving survives, right moving explodes
                    st.pop();
                }else if(right == abs(asteroid)){
                    //both explode
                    st.pop();
                    alive = false;
                }else{
                    //right-moving survies, left explodes
                    alive = false;
                }
            }
            if(alive){
                st.push(asteroid);
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};