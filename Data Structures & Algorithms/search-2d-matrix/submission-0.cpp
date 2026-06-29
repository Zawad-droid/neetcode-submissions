class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size() - 1;
        while(l <= h){
            int mid =  (l + h) / 2;
            if(matrix[mid][0] <= target && matrix[mid].back() >= target){
                int cl = 0;
                int ch = matrix[mid].size() - 1;
                while(cl <= ch){
                    int cmid =  (cl + ch) / 2;
                    if(matrix[mid][cmid] == target) return true;
                    else if(matrix[mid][cmid] < target) cl = cmid + 1;
                    else ch = cmid - 1;
                }
                return false;
            }
            else if(matrix[mid][0] < target && matrix[mid].back() < target) l = mid + 1;
            else h = mid - 1;
        }
        return false;
    }
};
