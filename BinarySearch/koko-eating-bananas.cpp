/* Question: https://leetcode.com/problems/koko-eating-bananas/

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Solution */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //P(X): S(x) <= h
        // FFFFFTT First T
        
        int low, high, mid;
        low = 1;
        high = *max_element(piles.begin(),piles.end());
        while(low<high){
            mid = low + (high-low)/2;
            if(Sum(piles, mid, h)<=h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    
    int Sum(vector<int> &piles, int bananasInOneHour,int h){
        int time = 0;  // Hours take to eat all bananas at speed bananasInOneHour.

        for(int i=0; i<piles.size(); i++){
            time +=  piles[i]/bananasInOneHour;
            if(piles[i] % bananasInOneHour != 0)
                time++;
        }
        return time;
    }
};
