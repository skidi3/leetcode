/* Question: https://leetcode.com/problems/majority-element-ii/

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

Solution */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int num1, num2 = -1;
        int counter1 = 0, counter2 = 0;
        int n = nums.size();
        if(nums.size()<=1) return nums;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==num1){
                counter1++;
            }
            else if(nums[i]==num2){
                counter2++;
            }
            else if(counter1==0){
                num1 = nums[i];
                counter1 = 1;
            }
            else if(counter2==0){
                num2= nums[i];
                counter2 = 1;
            }
            else{
                counter1--;
                counter2--;
            }
        }
        cout<<num1<<num2<< " ";
        //Reset counters
        counter1 = 0,counter2 = 0;
         
        for(int i=0; i<nums.size();i++){
            if(num1==nums[i]){
                counter1++;
            }
            else if(num2==nums[i]){
                counter2++;
            }
        }
        if(counter1>n/3){res.push_back(num1);}
        if(counter2>n/3){res.push_back(num2);}
        return res;
    }
};
