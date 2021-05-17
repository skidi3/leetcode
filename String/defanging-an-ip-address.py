'''
  Question : Defanging an IP Address
  https://leetcode.com/problems/defanging-an-ip-address/
  
  Given a valid (IPv4) IP address, return a defanged version of that IP address. A defanged IP address replaces every period "." with "[.]".
  
  Solution:
'''
class Solution:
    def defangIPaddr(self, address: str) -> str:
        res = ''
        for i in range(len(address)):
            if(address[i] == '.'):
                res += '[.]'
            else:
                res += address[i]
        return res;
