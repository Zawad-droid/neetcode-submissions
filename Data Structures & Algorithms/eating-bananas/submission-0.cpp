class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(auto i : piles){
            if(i > max) max = i;
        }
        int low = 1, high = max, mid = 0;
        while(low <= high){
            mid = (low + high) /2;
            double sum = 0.0;
            for(auto i : piles){
                sum += ceil((double)i / mid);
            }
            if(sum <= h) high = mid - 1;
            else low = mid + 1; 
        }
        return low;
    }
};
