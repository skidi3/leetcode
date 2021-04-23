/* Question: https://leetcode.com/problems/valid-palindrome/

Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Solution: */

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        if (empty(s)) return true;
        while(start<end){ 
            while(!isalnum(s[start]) && start<end)
                start++;
            while(!isalnum(s[end]) && start<end)
                end--;
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};
