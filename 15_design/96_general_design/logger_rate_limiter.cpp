#include <unordered_map>
#include <string>
using namespace std;

class Logger {
private:
    //message -> last printed timestamp
    unordered_map<string, int> lastPrinted;
public:
    Logger() {}
    bool shouldPrintMessage(int timestamp, string message) {
        //first time seeing this message
        if (!lastPrinted.count(message)) {
            lastPrinted[message] = timestamp;
            return true;
        }
        //has at least 10 seconds passed?
        if (timestamp - lastPrinted[message] >= 10) {
            //update last printed timestamp
            lastPrinted[message] = timestamp;
            return true;
        }
        return false;
    }
};

