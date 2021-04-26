/* Question: https://leetcode.com/problems/majority-element/

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Solution */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int res = 0;
        int partition = nums.size()/2;
        int counter = 1;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size()-1; i++){    
            int currValue = nums[i];
            int nextValue = nums[i+1];
            if(currValue==nextValue){
                counter++;
                res = currValue;
            }
            else{
                if(counter>partition){
                    return currValue;
                }
                else{
                    counter = 1;
                    res=currValue;
                }
            }
        }
        return res;    
    }
};
