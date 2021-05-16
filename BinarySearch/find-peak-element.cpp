/**
  Question : Find Peak Element
  https://leetcode.com/problems/find-peak-element/
  
  A peak element is an element that is strictly greater than its neighbors. 
  Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
  
  You may imagine that nums[-1] = nums[n] = -∞.
  You must write an algorithm that runs in O(log n) time.
  Solution :
  
**/
class Solution {
public:
    int findPeakElement(const vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high - 1) {
            int mid = low + (high-low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) 
                return mid;
            else if (nums[mid] > nums[mid + 1]) 
                    high = mid - 1;
                 else 
                    low = mid + 1;    
        }
        if (nums[low] > nums[high])
            return low;
        else
            return high;
    }
};
