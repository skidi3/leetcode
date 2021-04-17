/*Question: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

Solution:

/*

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //Initialize Result vector
        vector<int> res;
        //Base case
        if(nums.size()==0) return {-1,-1};
        //First Position
        //First T FFFFTTTT 
        //P(X): A[i] >= target
        int high,low,mid;
        low = 0, high = nums.size()-1;
        while(low<high){
            mid = low + (high-low)/2;
            
            if(nums[mid]>=target)
                high = mid;
            else
                low = mid + 1;
        }
        //Sanity check
        if(nums[high] != target)
            res.push_back(-1);
        else
            res.push_back(high);
        
        //Last Position
        //Last F FFFFFTTTT
        //P(X): A[i]<target
        low=0, high = nums.size()-1;
        while(low<high){
            mid = low + (high-low+1)/2;
            if(nums[mid]>target)
                high = mid - 1;
            else
                low = mid;
        }
        //Sanity check
        if(nums[high] != target)
            res.push_back(-1);
        else 
            res.push_back(high);
        //Return result
        return res;
    }
};
