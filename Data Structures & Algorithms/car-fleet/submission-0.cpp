class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec(position.size());
        for(int i = 0; i < position.size(); i++){
            vec[i] = {position[i], speed[i]};
        }
        ranges::sort(vec, ranges::greater());
        double bottleneck = 0.0;
        int fleet = 0;
        for(int i = 0; i < position.size(); i++){
            double time = (double) (target - vec[i].first) / vec[i].second;
            if(time > bottleneck){ 
                bottleneck = time;
                fleet++;
            }
        }
        return fleet;
    }
};
