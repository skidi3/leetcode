/* Question: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

A conveyor belt has packages that must be shipped from one port to another within D days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

Solution*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        //P(X): Time <= D
        // FFFTTTT First T
        
        int low, high, mid;
        low = *max_element(weights.begin(), weights.end());
        high = accumulate(weights.begin(), weights.end(), 0);
        while(low<high){
            mid = low + (high-low)/2;
            if(calcTime(weights, mid) <= D)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    
    int calcTime(vector<int> &weights, int minCapacity){
        int trips = 1, totalWeight=0;
        for(int i=0; i< weights.size(); i++){
            totalWeight += weights[i];
            if(totalWeight>minCapacity){
                trips++;
                totalWeight = weights[i];
            }        
        }
        return trips;
    }
    
};
