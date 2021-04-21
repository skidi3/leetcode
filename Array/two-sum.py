'''
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Solution :
'''


class Solution(object):
  
	def twoSum(self, nums, target):
    # creating a dict
		map_elements = {}
		for i in range(len(nums)):
      # finding elements in the dict if already present
			if nums[i] in map_elements:
				return [map_elements[nums[i]], i] 
			else:
        # add required number to pair
				map_elements[target - nums[i]] = i         
