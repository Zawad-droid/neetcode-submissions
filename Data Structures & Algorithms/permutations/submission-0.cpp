class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>comb;
        unordered_set<int>visited;
        dfs(nums, comb, visited);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& comb, unordered_set<int>& visited){
        if(comb.size() == nums.size()){
            res.push_back(comb);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited.count(nums[i])) continue;
            visited.insert(nums[i]);
            comb.push_back(nums[i]);
            dfs(nums, comb, visited);
            visited.erase(nums[i]);
            comb.pop_back();
        }
    }
};
