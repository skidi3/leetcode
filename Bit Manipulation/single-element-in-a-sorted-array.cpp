/*
  Question : https://leetcode.com/problems/single-element-in-a-sorted-array/
  Single Element in a Sorted Array
  
  You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
  Follow up: Your solution should run in O(log n) time and O(1) space.
  
  Solution :
  
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++)
            res^=nums[i];
        return res;
    }
};
