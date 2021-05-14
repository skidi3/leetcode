/*Question: https://leetcode.com/problems/unique-paths-ii/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Solution:*/
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        int p[][]=new int[obstacleGrid.length][obstacleGrid[0].length];
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        
        if(obstacleGrid[m-1][n-1]==1)
            return 0;
        
        if(m==1 && n==1 && obstacleGrid[0][0]==0)
            return 1;
        for(int i=m-2;i>=0;i--)
        {
            if(obstacleGrid[i][n-1]==1)
                break;
            else if(obstacleGrid[i][n-1]==0)
                p[i][n-1]=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(obstacleGrid[m-1][i]==1)
                break;
            else if(obstacleGrid[m-1][i]==0)
                p[m-1][i]=1;
        }
        
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                if(obstacleGrid[i][j]==1)
                    continue;
                if(obstacleGrid[i][j]==0 && obstacleGrid[i+1][j]==0)
                    p[i][j]+=p[i+1][j];
                
                if(obstacleGrid[i][j]==0 && obstacleGrid[i][j+1]==0)
                    p[i][j]+=p[i][j+1];
            }
        }
        return p[0][0];
        }
           
    }
