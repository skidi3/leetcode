'''
https://leetcode.com/problems/valid-parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
'''

class Solution:
    def isValid(self, s: str) -> bool:
        stack_parn = []
        for char in s:
            if ((char == '(') or (char == '{') or (char == '[')):
                stack_parn.append(char)
            else:
                if(len(stack_parn)==0):
                    return False
                if(char == ')' and stack_parn[-1] != '('):
                    return False
                if(char == '}' and stack_parn[-1] != '{'):
                    return False
                if(char == ']' and stack_parn[-1] != '['):
                    return False
                stack_parn.pop()
                
        return len(stack_parn) == 0
