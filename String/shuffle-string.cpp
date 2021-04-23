/* Question: https://leetcode.com/problems/shuffle-string/

Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

Solution: */

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        for(int i=0; i<s.size(); i++){
            res[indices[i]] = s[i];
        }
        return res;
    }
};
