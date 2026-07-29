#include <vector>
#include <queue>
using namespace std;

class HitCounter {
private:
    queue<int> hits;
public:
    HitCounter() {}

    void hit(int timestamp) {
        hits.push(timestamp);
    }

    int getHits(int timestamp) {
        int total = 0;
        while (!hits.empty() && hits.front() <= timestamp - 300) {
            hits.pop();
        }
        return hits.size();
    }
};