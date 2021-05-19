/**
  Question : https://leetcode.com/problems/search-a-2d-matrix-ii/
  Search a 2D Matrix II
  Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:
    - Integers in each row are sorted in ascending from left to right.
    - Integers in each column are sorted in ascending from top to bottom.
  
  Solution :
**/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int m = matrix[0].size();
        int n = matrix.size();
        int j = m-1;
        while((i>=0 && i<n) && (j>=0 && j<m))
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
        }
        return false;
    }
};
