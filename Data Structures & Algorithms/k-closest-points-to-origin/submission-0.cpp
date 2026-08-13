class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using PQ_Element = pair<int, vector<int>>;
        priority_queue<PQ_Element, vector<PQ_Element>, greater<PQ_Element>> pq;
        for(auto i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = (x * x) + (y * y);
            pq.push({dist, {x, y}});
        }
        vector<vector<int>> res;
        int i = 0;
        while(i < k){
            res.push_back({pq.top().second[0], pq.top().second[1]});
            pq.pop();
            i++;
        }
        return res;
    }
};
