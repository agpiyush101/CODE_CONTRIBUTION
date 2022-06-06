/*
LEETCODE 410. Split Array Largest Sum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)
*/

class Solution {
public:
  int check(vector<int>&nums,int m,int n,int possible_sum)
  {
    int sum=0;
    int cnt=1;
    for(auto x:nums)
    {
      if(x>possible_sum)
        return 0;
      sum+=x;
      if(sum>possible_sum)
      {
        sum=x;
        cnt++;
      }
      if(cnt>m)
        return 0;
    }
    if(cnt>m)
      return 0;
    else
      return 1;
  }
    int splitArray(vector<int>& nums, int m) {
      
     int n=nums.size();
      int minsum=INT_MAX;
      int maxsum=0;
      for(auto x:nums)
      {
        if(minsum>x)
        {
          minsum=x;
        }
        maxsum+=x;
      }
      int ans=0;
      cout<<minsum<<" "<<maxsum;
      
      
      while(minsum<=maxsum)
      {
        int possible_sum=maxsum+(minsum-maxsum)/2;
        cout<<possible_sum<<endl;
        if(check(nums,m,n,possible_sum))
        {
          
          ans=possible_sum;
          maxsum=possible_sum-1;
        }
        else
        {
          minsum=possible_sum+1;
        }
      }
      return ans;
        
          
        
    }
};
