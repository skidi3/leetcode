/*Question: You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.

Solution:
*/
class Solution {
public:
    string interpret(string command) {
        int n=command.size(), i=0;
        string ans;
        while(i<n){
            if(command[i]=='('){
                if(command[i+1]=='a'){
                    ans.push_back('a');
                    ans.push_back('l');
                    i+=4;
                }
                else{
                    ans.push_back('o');
                    i+=2;
                }
            }
            else{
                ans.push_back('G');
                i++;
            }
        }
        return ans;
    }
};
