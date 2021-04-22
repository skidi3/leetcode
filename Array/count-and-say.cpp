/* Question: https://leetcode.com/problems/count-and-say/

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251"

Solution: */

class Solution {
public:
    string countAndSay(int n) {
        
        //Base cases
        if(n==1) {return "1";}
        if(n==2) {return "11";}
        
        string res = "11";
        
        for(int i=3; i<=n; i++){
            string curr = "";
            for(int j=0; j<res.length();j++){
                int letter_counter = 1;
                while(j+1<res.size() && res[j]==res[j+1]){
                    letter_counter++;
                    j++;
                }
                curr += to_string(letter_counter) + res[j];
            }
            res = curr;
        }
        
        return res;
        
    }
};
