#include <unordered_set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);
        int level = 1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string word = q.front();
                q.pop();
                if(word == endWord) return level;
                for(int i=0; i<(int)word.size(); i++){
                    char original = word[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        word[i] = c;
                        if(dict.count(word)){
                            dict.erase(word);
                            q.push(word);
                        }
                    }
                    word[i] = original;
                }
            }
            level++;
        }
        return 0;
    }
};