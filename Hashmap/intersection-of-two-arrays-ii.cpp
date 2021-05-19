/**
  Question : https://leetcode.com/problems/intersection-of-two-arrays-ii/
  Intersection of Two Arrays II
  Given two integer arrays nums1 and nums2, return an array of their intersection. 
  Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
  
  Solution:
**/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
            mp[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
        {
            if(--mp[nums2[i]] >= 0)
                res.push_back(nums2[i]);
        }
        return res;
    }
};
