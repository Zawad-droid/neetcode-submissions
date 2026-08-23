class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            vector<int>count(26, 0);
            for(char c : strs[i]){
                count[c - 'a']++;
            }
            string key = "";
            for(int j = 0; j < 26; j++){
                key += "#" + to_string(count[j]);
            }
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(const auto& str : mp){
            res.push_back(str.second);
        }
        return res;
    }
};
