/* Question: Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.


Solution:
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_ele, n=candies.size();
        max_ele = *max_element(candies.begin(), candies.end());
        vector<bool> ans(n, false);
        
        for(int i=0; i<n; i++){
            if(max_ele-candies[i]<=extraCandies){
                ans[i]=true;
            }
        }
        
        return ans;
    }
};
