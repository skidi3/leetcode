/* Question: https://leetcode.com/problems/jump-game/

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Solution: */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPosition = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxPosition < i){
                return false;
            }
            maxPosition = max(i + nums[i], maxPosition); 
        }
        return true;
    }
};
