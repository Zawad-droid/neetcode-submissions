class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int max = 0;
        for(int r = 1; r < prices.size(); r++){
            if(prices[l] > prices[r]) l = r;
            else{
                int profit = prices[r] - prices[l];
                if(max < profit) max = profit;
            }
        }
        return max;
    }
};
