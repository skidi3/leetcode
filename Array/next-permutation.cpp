/* Question: https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Solution: */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        int pointer = nums.size()-2;
        while(pointer>=0 && nums[pointer]>=nums[pointer+1]){
            pointer--;
        }
        if(pointer==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1; i>pointer;i--){
            if(nums[i]>nums[pointer]){
                int temp = nums[pointer];
                nums[pointer] = nums[i];
                nums[i] = temp;
                break;
            }
        }
        reverse(nums.begin()+pointer+1, nums.end());
    }
};
