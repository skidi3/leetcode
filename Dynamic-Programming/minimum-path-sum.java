/*Question: https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Solution
*/
class Solution {
    public int minPathSum(int[][] grid) {
        
        int m=grid.length;
        int n=grid[0].length;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                    continue;
                if((i+1)==m && (j+1)!=n)
                    grid[i][j]+=grid[i][j+1];
                else if((i+1)!=m && (j+1)==n)
                    grid[i][j]+=grid[i+1][j];
                else
                    grid[i][j]+=Math.min(grid[i+1][j],grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
}
