class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>tmap;
        for(auto i : t) tmap[i]++;
        int min_len = INT_MAX;
        int l = 0, r = 0;
        unordered_map<char, int>winmap;
        int have = 0, need = tmap.size();
        int start_index = 0;
        while(r < s.size()){
            if(tmap.count(s[r])){
                winmap[s[r]]++;
                if(winmap[s[r]] == tmap[s[r]]) have++;
            }
            while(have == need){
                if(r - l + 1 < min_len){
                    min_len = r - l + 1;
                    start_index = l;
                }

                if(tmap.count(s[l])){
                    winmap[s[l]]--;
                    if(winmap[s[l]] < tmap[s[l]]) have--;
                }
                l++;
            }
            r++;
        }
        return min_len == INT_MAX ? "" : s.substr(start_index, min_len);
    }
};
