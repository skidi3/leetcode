/*Question:https://leetcode.com/problems/01-matrix/
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Solution:*/

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m=mat.length;
        int n=mat[0].length;
        int res[][]=new int[m][n];
        
        for(int i=0;i<m;i++)
            Arrays.fill(res[i],Integer.MAX_VALUE-100000);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                    res[i][j]=0;
                else
                {
                    if(i>0)
                        res[i][j]=Math.min(res[i][j],res[i-1][j]+1);
                    if(j>0)
                        res[i][j]=Math.min(res[i][j],res[i][j-1]+1);
                }
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(mat[i][j]==0)
                    res[i][j]=0;
                else
                {
                    if(i<m-1)
                        res[i][j]=Math.min(res[i][j],res[i+1][j]+1);
                    if(j<n-1)
                        res[i][j]=Math.min(res[i][j],res[i][j+1]+1);
                }
            }
        }
        
        return res;
    }
          
    }
