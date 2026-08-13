class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        while(n > 1){
            int x = n - 2;
            int y = n - 1;
            int nw = 0;
            if(stones[x] == stones[y]){
                stones.pop_back();
                stones.pop_back();
            } 
            else if(stones[x] < stones[y]){
                nw = stones[y] - stones[x];
                stones.pop_back();
                stones.pop_back();
                stones.push_back(nw);
            }
            n = stones.size();
            sort(stones.begin(), stones.end());
        }
        return (n == 1) ? stones[0] : 0;
    }
};
