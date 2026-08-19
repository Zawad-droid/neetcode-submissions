class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26);
        for(auto task : tasks){
            arr[task - 'A']++;
        }
        priority_queue<int> maxHeap;
        for(auto count : arr){
            if(count > 0) maxHeap.push(count);
        }
        queue<pair<int, int>> q;
        int timer = 0;
        while(!maxHeap.empty() || !q.empty()){
            timer++;
            if(!maxHeap.empty()){
                int count = maxHeap.top();
                maxHeap.pop();
                int remain = count - 1;
                if(remain > 0){
                    q.push({remain, timer + n});
                }
            }
            if(!q.empty() && q.front().second == timer){
                int count = q.front().first;
                q.pop();
                maxHeap.push(count);
            }
        }
        return timer;
    }
};
