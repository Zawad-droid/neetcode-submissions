class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        array<int, 26> tar_count = {0};
        array<int, 26> win_count = {0};
        for(int i = 0; i < s1.size(); i++){
            tar_count[s1[i] - 'a']++;
            win_count[s2[i] - 'a']++;
        }
        if(tar_count == win_count) return true;
        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++){
            win_count[s2[r] - 'a']++;
            win_count[s2[l] - 'a']--;
            l++;
            if(tar_count == win_count) return true;
        }
        return false;
    }
};
