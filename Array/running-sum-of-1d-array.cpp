/* Question: Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Solution: */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int prevSum = nums[0];
        res.push_back(prevSum);
        for(int i=1; i<n; i++){
            prevSum += nums[i];
            res.push_back(prevSum);
        }
        return res;
    }
};
