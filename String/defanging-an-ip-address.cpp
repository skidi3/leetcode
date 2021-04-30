/*Question: Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".


Solution:
*/
class Solution {
public:
    string defangIPaddr(string address) {
        int n=address.size();
        string ans;
        for(int i=0; i<n; i++){
            if(address[i]=='.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }
            else{
                ans.push_back(address[i]);
            }
        }
        return ans;
    }
};
