/*Question:https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Solution:*/

class Solution {
    public int longestPalindromeSubseq(String s) {
        
        int t[][]=new int[s.length()+1][s.length()+1];
        String s1="";
        for(int i=0;i<s.length();i++)
            s1=s.charAt(i)+s1;
        int res=0;
        for(int i=0;i<s.length()+1;i++)
        {
            for(int j=0;j<s.length()+1;j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
                else if(s.charAt(i-1)==s1.charAt(j-1))
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=Math.max(t[i-1][j],t[i][j-1]);
                res=Math.max(res,t[i][j]);
            }
        }
        return res;
    }
}
