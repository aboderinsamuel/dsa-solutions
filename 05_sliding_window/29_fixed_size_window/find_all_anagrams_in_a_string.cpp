class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for(char c : p){
            need[c - 'a']++;
        }

        int left = 0;
        for(int right= 0; right< s.size(); right++){
            //add right character
            window[s[right] - 'a']++;

            //keep window size
            if(right-left+1 > p.length()){
                window[s[left]-'a']--;
                left++;
            }
            if(window == need){
                ans.push_back(left);
            }
        }
        return ans;
    }
};