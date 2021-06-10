/* Question:
Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number
O(n) complexxity

Solution: */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == max1 || nums[i] == max2 || nums[i] == max3){
                continue;
            }
            if(nums[i]>max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i]>max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3){
                max3 = nums[i];
            }
        }
        if(max3 != LONG_MIN) return max3;
        return max1;
    }
};s
