/*
Question : https://leetcode.com/problems/group-anagrams/
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Solution :
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > table;
        vector<vector<string>> res;
        int i, n=strs.size();
        string sortedStr;
        unordered_map<string,vector<string>>::iterator it1;
        for(i = 0;i<n;i++){
            sortedStr = strs[i];
            sort(sortedStr.begin(),sortedStr.end());
            table[sortedStr].push_back(strs[i]);
        }
        for (it1=table.begin();it1!=table.end();it1++){
            res.push_back(it1->second);
        }
        return res;
    }
};
