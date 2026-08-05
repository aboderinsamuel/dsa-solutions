#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInMap; // userId -> (stationName, checkInTime)
    unordered_map<string, pair<long long, int>> travelData; // "startStation->endStation" -> (totalTravelTime, tripCount)
public:
    UndergroundSystem() {
    }
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    void checkOut(int id, string stationName, int t) {
        //Get start station and check-in time for the user
        auto [startStation, checkInTime] = checkInMap[id];
        //Calculate travel time
        int travelTime = t - checkInTime;
        //Create a key for the travel data
        string key = startStation + "->" + stationName;
        //Update total travel time and trip count
        travelData[key].first += travelTime;
        travelData[key].second += 1;
        //Remove the user from check-in map
        checkInMap.erase(id);
    }
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "->" + endStation;
        auto [totalTravelTime, tripCount] = travelData[key];
        return static_cast<double>(totalTravelTime) / tripCount;
    }
};