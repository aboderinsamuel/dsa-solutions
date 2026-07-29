#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> seen(deadends.begin(), deadends.end());
        if(seen.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        seen.insert("0000");
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string s = q.front();
                q.pop();
                if(s == target) return level;

                for(int i=0; i<4; ++i){
                    char orig = s[i];
                    int d = orig - '0';
                    for(int delta : {1,9}){
                        s[i] = '0' + (d+delta) % 10;
                        if(!seen.count(s)){
                            seen.insert(s);
                            q.push(s);
                        }
                    }
                    s[i] = orig;
                }
            }
            level++;
        }
        return -1;
    }
};