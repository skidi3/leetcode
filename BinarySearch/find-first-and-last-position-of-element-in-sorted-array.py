'''
  Question : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
  Find First and Last Position of Element in Sorted Array
  
  Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
  If target is not found in the array, return [-1, -1].
  You must write an algorithm with O(log n) runtime complexity.
  
  Solution:
  
'''
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if (len(nums) == 0):
            return [-1,-1]
        lo = 0
        hi = len(nums)-1
        # first true 
        while (lo < hi):
            mid = lo + (hi-lo)//2
            if(nums[mid] >=target):
                hi = mid
            else:
                lo = mid+1
        if nums[lo] == target:
            return [lo,lo+nums.count(target)-1]
        else:
            return [-1,-1]
