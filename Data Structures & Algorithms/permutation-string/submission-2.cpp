class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        unordered_map<char, int> tar_map;
        unordered_map<char, int> count_map;
        for(auto i : s1){
            tar_map[i]++;
        }
        for(int i = 0; i < s1.size(); i++){
            count_map[s2[i]]++;
        }
        if(tar_map == count_map) return true;
        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++){
            count_map[s2[l]]--;
            if(count_map[s2[l]] == 0) count_map.erase(s2[l]);
            l++;
            count_map[s2[r]]++;
            if(tar_map == count_map) return true;
        }
        return false;
    }
};
