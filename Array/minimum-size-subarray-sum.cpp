/* Question: https://leetcode.com/problems/minimum-size-subarray-sum/

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray 
[numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Solution*/ 

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()<1) return 0;
        int start = 0;
	    int currSum = 0;
	    int minValue = INT_MAX;
	    for(int i=0; i<nums.size(); i++){
	        currSum = currSum + nums[i];
	        while(currSum>=s){
	            minValue = min(minValue, i-start+1);
	            currSum = currSum - nums[start];
	            start++;
	        }
	    }
        if(minValue == INT_MAX) return 0;
	    return minValue;
    }
};

 
