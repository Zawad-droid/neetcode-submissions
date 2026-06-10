class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums){
            s.insert(i);
        }
        int maxLength = 0;
        int start, length = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s.count(nums[i] - 1) == 0){
                start = nums[i];
                length = 1;
                while(s.count(start + 1)){
                    start++;
                    length++;
                }
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};
