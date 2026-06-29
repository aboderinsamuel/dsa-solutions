class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        vector<int> need(128, 0);

        //frequency map for characters in t
        for(char c : t){
            need[c]++;
        }
        int left = 0;
        int required = t.length(); //total chars needed to match
        int min_len = INT_MAX;
        int min_start = 0;

        //sliding window
        for(int right = 0; right < s.length(); right++){
            char c = s[right];

            //if current char is needed
            if(need[c] > 0){
                required--; //found a required char
            }
            need[c]--; //decrease the need

            //when we have a valid window (all chars matched)
            while(required == 0){
                //update minimum window
                int curr_len = right-left+1;
                if(curr_len < min_len){
                    min_len = curr_len;
                    min_start = left;
                }
                //shrink from left
                char left_char = s[left];
                need[left_char]++; //increase need back
                if(need[left_char] > 0){
                    required++; //now we need this character again
                }
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};