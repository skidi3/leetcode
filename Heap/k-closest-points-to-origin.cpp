/*
  Question : https://leetcode.com/problems/k-closest-points-to-origin/
  K Closest Points to Origin
  Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
  The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
  You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
  
  Solution :
  
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxh;
        vector<vector<int>> res;
        for(int i=0;i<points.size();i++)
        {
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxh.push({distance, i});
            if(maxh.size()>k) maxh.pop();
        }
        while(maxh.size() > 0)
        {
            res.push_back(points[maxh.top().second]);
            maxh.pop();
        }
        return res;
    }
};
