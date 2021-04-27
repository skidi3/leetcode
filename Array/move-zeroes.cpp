/* Question: https://leetcode.com/problems/move-zeroes/

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Solution */

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int start = 0;
        int end = start+1;
        while(start <= arr.size()-1 && end <= arr.size()-1){
            //Nonzero-zero || Nonzero-nonzero
            if(arr[start]!=0){
                start++;
                end++;
            }
            else{
                //Zero-zero
                if(arr[end]==0){
                    end++;
                }
                //Zero=nonzero
                else if(arr[end]!=0){
                    swap(arr[start],arr[end]);
                    start++;
                    end++;
                }
            } 
        }
    }
};
