#include <unordered_set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(!words.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);
        int length = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string word = q.front();
                q.pop();
                if(word == endWord) return length;

                for(int i=0; i<word.size(); i++){
                    char original = word[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        word[i] = c;
                        if(!words.count(word)) continue;
                        if(visited.count(word)) continue;
                        visited.insert(word);
                        q.push(word);
                    }
                    word[i] = original;
                }
            }
            length++;
        }
        return 0;
    }
};