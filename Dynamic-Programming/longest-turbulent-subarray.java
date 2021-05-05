/*Question:https://leetcode.com/problems/longest-turbulent-subarray/

Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.

Output:
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

Solution:*/
class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int pg[]=new int[arr.length];
        int pl[]=new int[arr.length];
        
        for(int i=0;i<arr.length;i++)
        {
            pg[i]=0;pl[i]=0;
        }
        if(arr.length==1)
            return 1;
        if(arr[0]>arr[1])
            pg[0]=1;
        if(arr[0]<arr[1])
            pl[0]=1;
        
        for(int i=1;i<arr.length-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                pg[i]=pl[i-1]+1;
            }
            if(arr[i]<arr[i+1])
                pl[i]=pg[i-1]+1;
        }
        int max=0;
        for(int i=0;i<arr.length;i++)
        {
            if(pg[i]>max)
                max=pg[i];
            if(pl[i]>max)
                max=pl[i];
        }
        return max+1;
    }
}
