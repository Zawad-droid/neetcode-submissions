class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }
        int l = 0;
        vector<int> res;
        res.push_back(pq.top().first);
        for(int r = k; r < nums.size(); r++){
            pq.push({nums[r], r});
            int val_left = r - k + 1;
            while(pq.top().second < val_left){
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        return res;
    }
};
