/*Question:https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Solution:*/
class Solution {
    public int maxSubArray(int[] nums) {
        
        if(nums.length==1 )
            return nums[0];
        int n=nums.length,sum=0;
        int dp[]=new int[n];
        dp[0]=nums[0];
        int max=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=Math.max(nums[i],nums[i]+dp[i-1]);
            max=Math.max(max,dp[i]);
        }
        return max;
    }
}
