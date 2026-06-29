class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for(int i=0; i<position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        int fleets = 0;
        double fleetTime = 0;

        for(int i=cars.size()-1; i>=0; i--){
            double currentTime = (double)(target - cars[i].first) / cars[i].second;

            if(currentTime > fleetTime){
                fleets++;
                fleetTime = currentTime;
            }
        }
        return fleets;
    }
};