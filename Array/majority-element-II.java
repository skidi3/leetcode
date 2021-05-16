/*Question: https://leetcode.com/problems/majority-element-ii/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Input: nums = [3,2,3]
Output: [3]

Solution:*/
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        
        Arrays.sort(nums);
        List<Integer> list=new ArrayList<Integer>();
        for(int i=0;i<nums.length;i++)
        {
            if(list.contains(nums[i]))
                continue;
            if(map.containsKey(nums[i]))
                map.replace(nums[i],map.get(nums[i])+1);
            else
                map.put(nums[i],1);
            if(map.get(nums[i])>nums.length/3 )
                list.add(nums[i]);
        }
        return list;
    }
}
