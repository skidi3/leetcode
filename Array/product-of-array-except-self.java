/*Question:https://leetcode.com/problems/product-of-array-except-self/
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Solution:*/
class Solution {
    public int[] productExceptSelf(int[] nums) {
        
        int prd[]=new int[nums.length];
        for(int i=0;i<nums.length;i++)
            prd[i]=1;
        int temp=1;
        for(int i=0;i<nums.length;i++)
        {
            prd[i]=temp;
            temp*=nums[i];
        }
        temp=1;
        for(int i=nums.length-1;i>=0;i--)
        {
            prd[i]*=temp;
            temp*=nums[i];
        }
        return prd;
    }
}
