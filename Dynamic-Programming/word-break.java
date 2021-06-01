/*Question:https://leetcode.com/problems/word-break/
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Solution:*/
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        String t="";
        int n=s.length();
        boolean dp[]=new boolean[n+1];
        dp[n]=true;//empty string
        
        for(int i=n-1;i>=0;i--)
        {
            t="";
            for(int j=i;j<n;j++)
            {
                t+=s.charAt(j);
                if(wordDict.contains(t))
                {
                    if(dp[j+1])
                        dp[i]=true;
                }   
            }
        }
        return dp[0];
    }
}
