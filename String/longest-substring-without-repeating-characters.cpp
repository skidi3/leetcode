/* Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.

Solution: */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Base Case
        if(s.size()==1){return 1;}
        int i = 0;
        int j = 0;
        int finalCounter = 0;
        unordered_map<char,int> map;
        while(j<s.size()){
            if(map.find(s[j]) != map.end()){
                i = max(i, map[s[j]]+1);
            }
            map[s[j]] = j;
            finalCounter = max(j-i+1,finalCounter);
            j++;
        
        }
        return finalCounter;
    }
};
