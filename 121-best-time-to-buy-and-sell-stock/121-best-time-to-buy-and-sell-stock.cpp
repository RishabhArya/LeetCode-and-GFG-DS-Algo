class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minVal){
                minVal = prices[i];continue;}
            if(prices[i] - minVal > maxProfit)
                maxProfit = prices[i] - minVal;;
        }
        return maxProfit;
    }
};