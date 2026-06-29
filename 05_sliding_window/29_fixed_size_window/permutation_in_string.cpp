class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26, 0);
        for(char c : s1){
            need[c - 'a']++;
        }
        vector<int> window(26, 0);
        int left = 0;

        for(int right=0; right<s2.size(); right++){
            window[s2[right] - 'a']++;
            if(right-left+1 > s1.size()){
                window[s2[left] - 'a']--;
                left++;
            }
            if(window == need){
                return true;
            }
        }
        return false;
    }
};