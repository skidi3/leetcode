/* Question: https://leetcode.com/problems/jump-game-ii/

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Solution: */

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int position = 0;
        int distance = 0;
        for(int i = 0; i< nums.size()-1; i++){
            distance = max(nums[i]+i, distance);
            if(position == i){
                position = distance;
                jump++;
            }
        }
        return jump;
    }
};
