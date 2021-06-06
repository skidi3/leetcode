/*Question:https://leetcode.com/problems/find-peak-element/submissions/

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Solution:*/
class Solution {
    public int findPeakElement(int[] nums) {
        int lo=0,hi=nums.length-1;
        while(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            if( mid-1>=0 && mid+1< nums.length && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                return mid;
            else if(nums[mid]<nums[mid+1])
                lo=mid+1;
            else
                hi=mid;
        }
        return lo;
    }
}
