/* Question: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Solution: */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()<=1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval = intervals[0];
        
        for(int i=1; i<intervals.size(); i++){
            //Overlapping condition
            if(tempInterval[1]>=intervals[i][0]){
                tempInterval = {min(tempInterval[0],intervals[i][0]),max(tempInterval[1],intervals[i][1])};   
            }
            //Doesn't overlaps
            else{ 
                res.push_back(tempInterval);
                tempInterval = intervals[i];
            }         
        }
        res.push_back(tempInterval);
        return res;
    }
};
