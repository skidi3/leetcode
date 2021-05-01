/* Question: https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines 
are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the 
x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

Solution: */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxArea=0;
        int currArea;
        while(start<end){
            if(height[start]<height[end]){
                currArea = height[start]*(end-start);
                start++;
            }
            else{
                currArea = height[end]*(end-start);
                end--;
            }
            if(currArea>maxArea){
                maxArea = currArea;
            }
        }
        return maxArea;
    }
};
