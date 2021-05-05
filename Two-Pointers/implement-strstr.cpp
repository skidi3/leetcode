/* Question: https://leetcode.com/problems/implement-strstr/
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Solution: */

class Solution {
public:
    int strStr(string haystack, string needle) {
        //Base Case
        if(needle.size()==0) return 0;
        //Close window
        int p1=0,p2=0,i=0;
        //Open window and find a solution
        while(p2<haystack.size()){
            if(haystack[p2]==needle[i]){
                p2++;
                i++;
            }
            else{ 
                p1++;
                p2 = p1;  //close widow
                i = 0;
            }
            //Check if we found needle
            if(i==needle.size()){
                return p1;
            }
        }
        return -1;
    }
};
