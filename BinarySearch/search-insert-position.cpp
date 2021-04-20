/* Question: https://leetcode.com/problems/search-insert-position/
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
return the index where it would be if it were inserted in order.

Solution: */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high, low, mid;
        low = 0,  high = nums.size()-1;
        while(low<high){
            //P(X): target<A[i]
            // FFFFTTT last F 
            mid = low + (high-low+1)/2;
            if(nums[mid]>target)
                high = mid-1;
            else
                low = mid;
        }
        return nums[low] < target? low+1: low;
    }
};
