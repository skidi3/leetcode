/* Question: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

Solution: */

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //P(X): Sx <= Threshold
        // FFTTTT First T
        // Range: 1 to max(A[i])
        int low,high,mid;
        low = 1;
        high = *max_element(nums.begin(),nums.end());
        
        while(low<high){
            mid = low + (high-low)/2;
            if(Sum(nums, mid)<=threshold)
                high = mid;
            else
                low = mid + 1;
        }
        //No sanity check needed as it is guaranteed that there will be an answer.
        return low;
    }
    int Sum(vector<int> &nums, int divisor){
        int sum = 0;
        for(int i=0; i<nums.size();i++){
            sum += ceil((float)nums[i]/divisor);
        }
        return sum;
    }
};
