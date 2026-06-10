class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(const auto& pair : mp){
            bucket[pair.second].push_back(pair.first);
        }
        vector<int> res;
        int count = 0;
        for(int i = nums.size(); i >= 0; i--){
            if(bucket[i].size() > 0){
               if(count != k){
                 for(auto num : bucket[i]){
                    res.push_back(num);
                    count++;
                }
               }
            }
        }
        return res;
    }
};
