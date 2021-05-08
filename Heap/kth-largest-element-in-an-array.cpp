/*
  Question : https://leetcode.com/problems/kth-largest-element-in-an-array/
  Kth Largest Element in an Array
  
  Given an integer array nums and an integer k, return the kth largest element in the array. 
  Note that it is the kth largest element in the sorted order, not the kth distinct element.
  
  Solution :
  
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i:nums)
        {
            minh.push(i);
            if(minh.size() > k) minh.pop();
        }
        return minh.top();
    }
};
