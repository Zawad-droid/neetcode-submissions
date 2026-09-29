class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currsub;
        int index = 0, sum = 0;
        dfs(nums, index, target, currsub, sum);
        return res;
    }
    void dfs(vector<int>& nums, int index, int target, vector<int>&currsub, int sum){
        if(target == sum){
            res.push_back(currsub);
            return;
        }
        if(sum > target) return;
        if(index == nums.size()) return ;
        int num = nums[index];
        currsub.push_back(num);
        sum += num;
        dfs(nums,index, target, currsub, sum);
        currsub.pop_back();
        sum -= num;
        dfs(nums, index + 1, target, currsub, sum);
    }
};
