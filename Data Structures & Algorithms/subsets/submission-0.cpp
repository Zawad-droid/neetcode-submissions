class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<int>currsub;
        dfs(nums, currsub, index);
        return res;
    }
    void dfs(vector<int>&nums, vector<int>&currsub, int index){
        if(nums.size() == index){
            res.push_back(currsub);
            return;
        }
        currsub.push_back(nums[index]);
        dfs(nums, currsub, index + 1);
        currsub.pop_back();
        dfs(nums, currsub, index + 1);
    }
};
