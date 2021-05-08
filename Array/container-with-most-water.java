/*Question:https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Solution:*/
class Solution {
    public int maxArea(int[] height) {
        
        int res=-1,i=0,j=height.length-1;
        while(i<j)
        {
            res=Math.max(res,(Math.min(height[i],height[j])*(j-i)));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return res;
    }
}
