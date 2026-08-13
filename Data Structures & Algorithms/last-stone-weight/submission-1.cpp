class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone : stones) pq.push(stone);
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            int nw = 0;
            if(x < y){
                nw = y - x;
                pq.push(nw);
            }
        }
        return (pq.size() == 1) ? pq.top() : 0;
    }
};
