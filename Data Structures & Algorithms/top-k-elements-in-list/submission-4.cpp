class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto num : nums) mp[num]++;
        vector<vector<int>> buck(nums.size() + 1);
        for(const auto& [key, value] : mp){
            buck[value].push_back(key);
        }
        vector<int> res;
        for(int i = nums.size(); i >= 0; i--){
            if(buck[i].empty()) continue;
            for(auto num : buck[i]){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
