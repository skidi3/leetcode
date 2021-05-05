/* Question: Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.



Solution:
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
int n = A.size(), count = 0, max_count = 0, i;
        
        for(i=0; i < n; i++)
        {
            if ((i >= 2) && (((A[i-2]>A[i-1])&&(A[i-1]<A[i]))|| ((A[i-2]<A[i-1])&&(A[i-1]>A[i]))))             
            		count ++;
            else if((i >= 1) && (A[i-1]!=A[i]))
                count = 2;
            else
                count = 1;
            
            max_count=max(max_count,count);

        }    
        return max_count;
    }
};
