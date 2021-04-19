/* Question: https://leetcode.com/problems/search-a-2d-matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Solution */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) return false;
        int m,n;
        n = matrix.size();
        m = matrix[0].size();
        int low, high,mid;
        low = 0, high=(m*n)-1;
        while(low<high){
            //P(x): A[i]>=target
            //FFFTTT last F 
            mid = low + (high-low+1)/2;
            if(matrix[mid/m][mid % m] > target)
                high = mid - 1;
            else 
                low = mid;
        }
        if(matrix[low/m][low%m] == target)
            return true;
        else 
            return false;
    }
};
