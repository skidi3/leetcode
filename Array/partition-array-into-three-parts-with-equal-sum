/* Question: Given an array of integers arr, return true if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i + 1 < j with (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])


Solution:
*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size(), totalSum = 0, reqSum, currSum = 0, parCount = 0;
        
        for(int i=0; i<n; i++){
            totalSum+=A[i];
        }
        
        reqSum = totalSum/3;
        
        if(totalSum%3!=0){
            return false;
        }
        
        for(int i=0; i<n; i++){
            currSum+=A[i];
            if(currSum==reqSum){
                parCount++;
                currSum=0;
            }
        }
        
        
        if(parCount>=3){
            return true;
        }
        
        return false;
    }
};
