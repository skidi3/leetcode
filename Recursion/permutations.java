/*Question:https://leetcode.com/problems/permutations/
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Solution:*/
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        
        boolean visited[]=new boolean[nums.length];
        List<Integer> list=new ArrayList();
        List<List<Integer>> res=new ArrayList();
        perm(nums,visited,list,res);
        return res;
    }
    void perm(int[] nums,boolean[] visited,List<Integer> list,List<List<Integer>> res)
    {
        if(list.size()==nums.length)
        {
            res.add(new ArrayList(list));
            return;
        }
        
        for(int i=0;i<visited.length;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                list.add(nums[i]);
                perm(nums,visited,list,res);
                visited[i]=false;
                list.remove(list.size()-1);
            }
        }
    }
}
