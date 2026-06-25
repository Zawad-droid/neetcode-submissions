class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0; 
        int h = nums.size() - 1;
        if(target < nums[l]) return 0;
        if(target > nums[h]) return nums.size();
        while(l <= h){
            int mid = (l + h) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) l = mid + 1;
            else h = mid - 1;
        }
        return l;
    }
};