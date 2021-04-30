/* Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Solution: */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;   
        int maxProfit = 0;
        int costPrice = prices[0];
        for(int i = 0; i < prices.size(); i++){
            maxProfit = max(prices[i]-costPrice,maxProfit);
            costPrice = min(costPrice, prices[i]);
        }
        return maxProfit;
    }
};
