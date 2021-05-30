/*Question: https://leetcode.com/problems/maximum-product-subarray/
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Solution:*/
class Solution {
    public int maxProduct(int[] nums) {
        
        if(nums.length==1)
            return nums[0];
        int mx=nums[0];
        int maxp[]=new int[nums.length];
        int minp[]=new int[nums.length];
        maxp[0]=nums[0];minp[0]=nums[0];
        for(int i=1;i<nums.length;i++)
        {
            int x=Math.max(nums[i]*maxp[i-1],nums[i]*minp[i-1]);
            maxp[i]=Math.max(nums[i],x);
            
            int y=Math.min(nums[i]*minp[i-1],nums[i]*maxp[i-1]);
            minp[i]=Math.min(nums[i],y);
            
            mx=Math.max(mx,maxp[i]);
        }
        return mx;
    }
}
