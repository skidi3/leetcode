/*
  Question : https://leetcode.com/problems/find-k-closest-elements/
  Find K Closest Elements
  
  Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
  An integer a is closer to x than an integer b if:
    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b
  
  Solution :
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxh;
        vector<int> res;
        for(int i : arr)
        {
            maxh.push({abs(i - x), i});
            if(maxh.size()>k) maxh.pop();
        }
        while(maxh.size() > 0)
        {
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(res.begin(), res.end());
        return res;
            
    }
};
