/*Question: https://leetcode.com/problems/palindrome-partitioning/
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Solution:*/
class Solution {
    public List<List<String>> partition(String s) {
        
        List<List<String>> res=new ArrayList();
        List<String> list=new ArrayList();
        palindrome(s,list,res,0);
        return res;
    }
    void palindrome(String s,List<String> list,List<List<String>> res,int start)
    {
        if(start==s.length())
        {
            res.add(new ArrayList(list));
            return;
        }
        for(int i=start;i<s.length();i++)
        {
            if(isPalin(s,start,i))
            {
                list.add(s.substring(start,i+1));
                palindrome(s,list,res,i+1);
                list.remove(list.size()-1);
            }
        }
    }
    boolean isPalin(String s,int i,int j)
    {
     
        while(i<j)
        {
            if(s.charAt(i)!=s.charAt(j))
                return false;
            i++;j--;
        }
        return true;
    }
}
