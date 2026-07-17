#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    string encode(vector<string>& strs) {
        //this will hold the final encoded message
        string encoded = "";

        //visit every string in the input
        for (string str : strs) {
            //append:length+#+actual string
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        //store the recovered strings
        vector<string> result;
        //current position in the encoded string
        int i = 0;
        while (i < s.size()) {
            //j will move until it finds '#'
            int j = i;
            while (s[j] != '#') j++;
            //charactersfrom i to j-1 reps string length
            int length = stoi(s.substr(i, j-1));
            j++;
            result.push_back(s.substr(j, length));
            i = j + length;
        }
        return result;
    }
};