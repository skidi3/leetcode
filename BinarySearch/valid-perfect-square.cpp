/**
Question : Valid Perfect Square
https://leetcode.com/problems/valid-perfect-square/

Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt

Solution:
**/
class Solution {
public:
    bool isPerfectSquare(int num) {
        // sqrt -> 0 ,....., num
        int low = 0;
        int high = num;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if (pow(mid,2) == num) 
                return true;
            else if(pow(mid, 2) < num) 
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};
