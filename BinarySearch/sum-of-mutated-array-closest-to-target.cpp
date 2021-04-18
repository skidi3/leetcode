/* Question: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

Solution: */

class Solution {
public:
    
    int findBestValue(vector<int>& arr, int target) {
        int x = BS(arr, target, 0, *max_element(arr.begin(), arr.end()));   
        int sum1 = Sum(x, arr);
        int sum2 = Sum(x+1, arr);
        cout<<x<<" "<<sum1<<" "<<sum2;
        if(abs(sum1-target) <= abs(sum2-target))
            return x;
        else 
            return x+1;
    }
    
    int Sum(int value, vector<int> &arr){
        int sum = 0;
        for(int i=0; i< arr.size(); i++){
            if(arr[i]>value){
                sum += value; 
            }
            else 
                sum += arr[i];
        }
        return sum;
    }
    
    int BS(vector<int> &arr, int target, int low, int high){
        //P(X): S(x) > target
        // FFFTTTT Last F 
        // Range: 0 to max(A[i])
        int mid;
        while(low<high){
            mid = low + (high-low+1)/2;
            if(Sum(mid, arr)> target)
                high = mid - 1;
            else
                low = mid;
        }
        return low;
    }
};
