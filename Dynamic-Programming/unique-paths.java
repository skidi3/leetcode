/* Question:https://leetcode.com/problems/unique-paths/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Solution in JAVA*/

class Solution {
    public int uniquePaths(int m, int n) {
        
        int p[][]=new int[m][n];
        for(int i=0;i<m;i++)
            p[i][n-1]=1;
        
        for(int i=0;i<n;i++)
            p[m-1][i]=1;
       
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
                p[i][j]=p[i+1][j]+p[i][j+1];
        }
       
        return p[0][0];
    }
}
