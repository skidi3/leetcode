
/* Question: https://leetcode.com/problems/peak-index-in-a-mountain-array

 Let's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].


Solution */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //FFFFTTT
        //P(X): A[i] < A[i-1]
        //Last F
        int low,high,mid;
        low=0;
        high=arr.size()-1;
        while(low<high){
            mid = low + (high-low+1)/2;
            
            if(arr[mid]<arr[mid-1])
                high=mid-1;
            else
                low = mid;
        }
        return high;
    }
};
