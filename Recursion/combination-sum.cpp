/* Question: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Solution */ 

class Solution {
public:
    
    
    vector<vector <int>> combinationSumHelper(vector<int> &candidates, int start, int target){
        // 1) Base cases
        
        //Positive cases
        if(target==0) return {{}};
        
        //Negative cases
        if(target<0 || start == candidates.size()) return {};
        
        
        // 2) Recursive steps
        
        //Include
        vector<vector<int>> temp1 = combinationSumHelper(candidates, start,target-candidates[start]);
        
        //Exclude
        vector<vector<int>> temp2 = combinationSumHelper(candidates, start+1,target);
        
        //Push candidates[start] in include case
        for(int i=0;i<temp1.size();i++){
            temp1[i].push_back(candidates[start]);
        }
       
        // 3) Union of temp1 & temp2
        vector<vector<int>> res;
        for(int i=0;i<temp1.size();i++){
            res.push_back(temp1[i]);
        }
        for(int i=0;i<temp2.size();i++){
            res.push_back(temp2[i]);
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        res = combinationSumHelper(candidates,0,target);
        return res;
    }
};
