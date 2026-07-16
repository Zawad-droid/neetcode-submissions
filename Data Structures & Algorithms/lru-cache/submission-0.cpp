class LRUCache {
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key)){
            auto it = m[key];
            cache.splice(cache.begin(), cache, it);
            return it->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            auto it = m[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
        }
        else{
            if(cache.size() >= cap){
                m.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            m[key] =  cache.begin();
        }
    }
};
