class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.contains(key)) return "";
        int l = 0, h = mp[key].size() - 1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(mp[key][mid].first == timestamp) return mp[key][mid].second;
            else if(mp[key][mid].first < timestamp) l = mid + 1;
            else h = mid - 1;
        }
        if(h < 0) return "";
        return mp[key][h].second;
    }
};
