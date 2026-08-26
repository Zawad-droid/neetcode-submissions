class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>curComb;
        dfs(nums, 0, target, curComb);
        return res;
    }
    void dfs(vector<int>&nums, int index, int remTar, vector<int>& curComb){
        if(remTar == 0){
            res.push_back(curComb);
            return;
        }
        if(remTar < 0) return;
        for(int i = index; i < nums.size(); i++){
            if(nums[i] > remTar) break;
            curComb.push_back(nums[i]);
            dfs(nums, i, remTar - nums[i], curComb);
            curComb.pop_back();
        }
    }
};
