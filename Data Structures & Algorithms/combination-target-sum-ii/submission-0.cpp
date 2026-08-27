class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>comb;
        dfs(candidates, 0, target, comb);
        return res;
    }
    void dfs(vector<int>& candidates, int index, int target, vector<int>&comb){
        if(target == 0){
            res.push_back(comb);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            comb.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], comb);
            comb.pop_back();
        }
    }
};
