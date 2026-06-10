class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxsize = 0;
        while(left < right){
            int area = (right - left) * (min(heights[left], heights[right]));
            if(heights[left] < heights[right]) left++;
            else if(heights[right] < heights[left]) right--;
            else{
                right--;
                left++;
            }
            maxsize = max(maxsize, area);
        }
        return maxsize;
    }
};
