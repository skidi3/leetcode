/* Question: Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Solution:
*/
class Solution {
public:
    void fn(vector<int> &A, int start, vector<int> currSet, vector<vector<int>> &res){
        //Base Case
        if(start==A.size()){
            res.push_back(currSet);
            return;
        }

        
        //Recursive Step

                
        //Including A[start]
        //vector<int> currSetTemp(currSet);
        currSet.push_back(A[start]);
        fn(A, start+1, currSet, res);
        currSet.pop_back();
        
        //Excluding A[start]
        int i=start;
        while(A[start]==A[i]){
            i++;
            if(i==A.size()){
                break;
            }
        }
        fn(A, i, currSet, res);

    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currSet; 
        vector<vector<int>> res;
        vector<vector<int>> ans;
        fn(nums, 0, currSet, res);
        
        return res;
    }
};
