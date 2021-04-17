/* Question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

*/ 

class Solution {
public:
    int findMin(vector<int>& nums) {
        //FFFFTTT
        //First T
        //P(X): A[i] < A[0]
        int low, high, mid;
        low=0, high = nums.size()-1;
        while(low<high){
            mid = low + (high-low)/2;    
            if(nums[mid]<nums[0])
                high = mid;
            else
                low = mid + 1;
        }
      // Sanity check (F*T*)
        if(nums[low]<nums[0]) return nums[low];
      //F*
        return nums[0];
    }
};
