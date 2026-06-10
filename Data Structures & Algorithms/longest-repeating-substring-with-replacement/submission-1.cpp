class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int max_freq = 0;
        int length = 0;
        int l = 0;
        int r = 0;
        while(r < s.size()){
            mp[s[r]]++;
            max_freq = max(max_freq, mp[s[r]]);
            int replace = (r - l + 1) - max_freq;
            if(replace > k){
                mp[s[l]]--;
                l++;
            }
            length = max(length, r - l + 1);
            r++;
        }
        return length;
    }
};
