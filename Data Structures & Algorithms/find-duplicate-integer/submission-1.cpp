class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int num = abs(nums[i]);
            if(nums[abs(num)] < 0) return abs(num);
            nums[abs(num)] = (-1) * nums[abs(num)];
        }
        return 0;
    }
};
