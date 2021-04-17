/* Question: https://leetcode.com/problems/find-in-mountain-array/submissions/

(This problem is an interactive problem.)

You may recall that an array A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.  If such an index doesn't exist, return -1.

You can't access the mountain array directly.  You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

Solution: */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = findPeakIndex(target, mountainArr);
        int minValue1 = binarySearch1(mountainArr, 0, peakIndex, target);
        int minValue2 = binarySearch2(mountainArr, peakIndex, mountainArr.length()-1,target );
        if(minValue1 == -1 && minValue2 == -1) return -1;
        if(minValue1 == -1 && minValue2 != -1) return minValue2;
        if(minValue1 != -1 && minValue2 == -1) return minValue1;
        return min(minValue1,minValue2);
        
    }
    int findPeakIndex(int target, MountainArray &mountainArr){
        //P(X): A[i] < A[i-1]
        //FFFFTTT Last F
        int low, high, mid;
        low = 0;
        high = mountainArr.length()-1;
        while(low<high){
            mid = low + (high-low+1)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid-1))
                high = mid-1;
            else
                low = mid;
        }
        return high;
    }
    int binarySearch1(MountainArray &mountainArr, int low, int high, int target){
        //P(X): A[i] > target
        //Last F : FFFTTT
        int mid;
        while(low<high){
            mid = low + (high-low+1)/2;
            if(mountainArr.get(mid)>target)
                high = mid-1;
            else
                low = mid;
        }
        if(mountainArr.get(high)==target)
            return high;
        else 
            return -1;
    }
    int binarySearch2(MountainArray &mountainArr, int low, int high, int target){
        //P(X): A[i]<=target
        //FFTTTTT First T
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(mountainArr.get(mid)<=target)
                high=mid;
            else
                low=mid+1;
        }
        if(mountainArr.get(high)==target)
            return high;
        else 
            return -1;
    }
};
