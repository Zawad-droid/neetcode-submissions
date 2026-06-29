class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = (m * n) - 1;
        while(l <= h){
           int  mid = (l + h) / 2;
            int val = matrix[mid / n][mid % n];
            if(val == target) return true;
            else if(val < target) l = mid + 1;
            else h = mid - 1;
        }
        return false;

    }
};
