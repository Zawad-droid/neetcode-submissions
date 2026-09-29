class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currsub;
        int index = 0;
        dfs(nums, currsub, index);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& currsub, int index){
        if(index == nums.size()){
            res.push_back(currsub);
            return;
        }
        dfs(nums, currsub, index + 1);
        currsub.push_back(nums[index]);
        dfs(nums, currsub, index + 1);
        currsub.pop_back();

    }
};
