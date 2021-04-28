/*Question: Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

Solution:
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int counter=0, i, j, n=nums.size();
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(nums[i]==nums[j]){
                    counter++;
                }
            }
        }
        return counter;
    }
};
