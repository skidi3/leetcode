
/* Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in 
both subsets is equal.

Solution: */ 

class Solution {
public:
    bool isSubsetSum(vector<int> nums, int sum){
        int n = nums.size();
        bool t[n+1][sum+1];
        //Init
        for(int i=0; i<=n; i++)
            t[i][0] = true;
        for(int j=0; j<=sum; j++)
            t[0][j] = false;
        //Bottoms up approach
        for(int i=1; i<=n; i++){
            for(int j=1;j<=sum;j++){
                if(j<nums[i-1]){
                    t[i][j] = t[i-1][j];
                }
                else if(j>=nums[i-1]){
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                }
            }
        }
        return t[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        //Calc sum 
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        else{
            return isSubsetSum(nums, sum/2);
        }
    }
};
