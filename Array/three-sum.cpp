/* Question: https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Solution: */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end()); //O(nlogn)
        for(int i=0; i< (int)(nums.size())-2;i++){
            //If it's the first item or it's not duplicate
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low = i+1;
                int high = nums.size()-1;
                int sum = 0-nums[i];
                   
                while(low<high){        
                    if(nums[low] + nums[high]==sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                        
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        
                        low++;
                        high--; 
                    }
                    else if(nums[low] + nums[high]<sum) low++;
                    else high--;
                }
            }
        }
        return res;
    }
};
