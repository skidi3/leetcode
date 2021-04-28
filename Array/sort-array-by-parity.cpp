/* Question: https://leetcode.com/problems/sort-array-by-parity/

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Solution: */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        if(arr.size()<=1){return arr;}
        while(start<end){
            //even or even-even pairs
            if(arr[start]%2==0){
                start++;
            }  
            else{
                //Both odd pairs
                if(arr[end]%2!=0){
                    end--;
                }
                //odd-even pairs
                else if(arr[end]%2==0){
                    swap(arr[start],arr[end]);
                    start++;
                    end--;
                } 
            }
        }
        return arr;
    }
};
