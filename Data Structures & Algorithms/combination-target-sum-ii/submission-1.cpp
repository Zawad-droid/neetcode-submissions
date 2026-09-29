class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0, i = 0;
        vector<int>currsub;
        dfs(candidates, target, sum, currsub, i);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int sum, vector<int>& currsub, int i){
        if(sum == target){
            res.push_back(currsub);
            return;
        }
        if(sum > target) return;
        if(i == candidates.size()) return;
        currsub.push_back(candidates[i]);
        sum += candidates[i];
        dfs(candidates, target, sum, currsub, i + 1);
        currsub.pop_back();
        sum -= candidates[i];
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]){
            i++;
        }
        dfs(candidates, target, sum, currsub, i + 1);
    }
};
