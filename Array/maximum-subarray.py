'''
https://leetcode.com/problems/maximum-subarray/
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Solution :
'''
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
      
        total_sum = max_sum = nums[0]
        for i in nums[1:]:
            total_sum = max(i,total_sum+i)
            max_sum = max(max_sum,total_sum)
        return max_sum  
