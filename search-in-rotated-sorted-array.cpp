/* Question: https://leetcode.com/problems/search-in-rotated-sorted-array/

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Solution: */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
      
        if(nums.size()==0) return -1;
        if(nums.size()==1 && nums[0]==target) return 0;
        if(nums.size()==1 && nums[0] != target ) return -1;
        
        int breakIndex = 0;
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                breakIndex = i;
                break;
            }
        }
        
        
        vector<int> arr1(nums.begin(), nums.begin()+breakIndex+1);
        vector<int> arr2(nums.begin()+breakIndex+1, nums.end());
        
        int search1 = binarySearch(arr1, target);
        int search2 = binarySearch(arr2, target);
 
        if(search1 == -1 && search2 == -1) return -1;
        if(search1 == -1 && search2 != -1) return search2 + arr1.size();
        return search1;   
    }
    
    int binarySearch(vector<int> &arr, int target){    
        int low, high, mid;
        low=0, high=arr.size()-1;
        while(low<high){
            mid = low + (high-low)/2;
            if(arr[mid]>=target){
                high = mid;
            }
            else
                low = mid + 1;
        }
        if(arr[high] == target) return high;
        return -1;
    }
};
