#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        for (auto const& [startCard, freq] : count) {
            if (count[startCard] == 0) continue;

            int neededCount = count[startCard];
            for (int i=0; i<groupSize; i++) {
                if (count[startCard+i] < neededCount) {
                    return false;
                }
                count[startCard+i] -= neededCount;
            }
        }
        return true;
    }
};