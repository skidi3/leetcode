/*Question:https://leetcode.com/problems/word-search/
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Solution:*/
class Solution {
    public boolean exist(char[][] board, String word) {
        
        int m=board.length;
        int n=board[0].length;
        boolean vis[][]=new boolean[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word.charAt(0))
                {
                    boolean res=find(word,0,board,vis,i,j);
                    if(res)
                        return true;
                }
            }
        }
        return false;
    }
    boolean find(String word,int start,char[][]board,boolean[][] vis,int si,int sj)
    {
        if(start==word.length())
            return true;
        if(si<0 ||si>=vis.length || sj<0||sj>=vis[0].length)
            return false;

        if(vis[si][sj] || board[si][sj]!=word.charAt(start))
            return false;
        vis[si][sj]=true;
        
        boolean f=find(word,start+1,board,vis,si-1,sj)||find(word,start+1,board,vis,si,sj+1)||
            find(word,start+1,board,vis,si+1,sj)||find(word,start+1,board,vis,si,sj-1);
        
        vis[si][sj]=false;
        return f;
    }
}
