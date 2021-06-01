/*Question:https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

Given n orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

Solution:*/
class Solution {
    public int countOrders(int n) {
        long dp[]=new long[n+1];
        dp[0]=0;dp[1]=1;
        for(int i=2;i<n+1;i++)
        {
            int t=i*(2*i-1);
            dp[i]=(((dp[i-1])%1000000007)*((t)%1000000007))%1000000007;
        }
        return (int)(dp[n]);
    }
}
