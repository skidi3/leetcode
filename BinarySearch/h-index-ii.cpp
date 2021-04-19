/* Question: https://leetcode.com/problems/h-index-ii/

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in an ascending order, return compute the researcher's h-index.

According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.

Solution: */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0){
            return 0;
        }
        // P(X): A[i]>=n-i
        // FFTTTT First T
        int low, high, mid;
        low = 0;
        high = citations.size()-1;
        while(low<high){
            mid = low + (high-low)/2;
            if(citations[mid]>=citations.size()-mid)
                high = mid;
            else
                low = mid + 1;
        }
        return (citations[low]>=citations.size()-low)?citations.size()-low:0;
    }
};
