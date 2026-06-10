class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() < s.size() || t.size() > s.size()) return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> np;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            np[t[i]]++;
        }
        if(mp == np){
            return true;
        }
        return false;
        
    }
};
